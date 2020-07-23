#include <limits>
#include <iostream>
#include <vector>
#include <sys/mman.h>
#ifndef _ARENA_IMPL_H_
#define _ARENA_IMPL_H_
namespace arena
{
    struct Spanned_Address
    {
        void* address;
        bool used;
        size_t size_spanned;
    };
    inline size_t aligner(size_t n) {
        return (n + sizeof(intptr_t) - 1) & ~(sizeof(intptr_t) - 1);
    }
    inline unsigned long long getesp(){
        __asm__("movl %esp,%eax");
    }
} // namespace arena
template <class T>
class Arena{
        private:
            size_t size;
            void* own_address;
            void* hint_address;
            void* approximation_address;
            int pos;
            

        public:
            // type definitions
            typedef T        value_type;
            typedef T*       pointer;
            typedef const T* const_pointer;
            typedef T&       reference;
            typedef const T& const_reference;
            typedef std::size_t    size_type;
            typedef std::ptrdiff_t difference_type;
            // rebind allocator to type U
            template <class U>
            struct rebind{
                typedef Arena<U> other;
            };
            
            static int mapped_count;
            static int mapped_but_notused;  
            static std::vector<arena::Spanned_Address> Mapped_Address_Space;
            // return address of values
            pointer address (reference value) const;
            const_pointer address (const_reference value) const;



            Arena(size_t n, void* h,unsigned long long hotness) throw();
            Arena(const Arena&) throw();
            template <class U>
              Arena (const Arena<U>&) throw();
            ~Arena() throw();
            // return maximum number of elements that can be allocated
            size_type max_size () const throw();
            // allocate but don't initialize num elements of type T
            pointer allocate ();
            pointer allocate (int previousDealloc);
            // initialize elements of allocated storage p with value value
            void construct (pointer p, const T& value);
            // destroy elements of initialized storage p
            void destroy (pointer p);
            // deallocate storage p of deleted elements
            void deallocate ();
            void flushArena ();

            inline void generaldealloc(void*);
            inline void *getHintAddress();
            inline int replacable(size_t n);
};
#ifndef IMPLEMENT_ARENA
#define IMPLEMENT_ARENA
            template<class T>
            T* Arena<T>::address (reference value) const {
                return &value;
            }
            template<class T>
            const T* Arena<T>::address (const_reference value) const {
                return &value;
            }


            template<class T>
			Arena<T>::Arena(size_t n, void* h,unsigned long long hotness) throw() {
                size = (max_size() >= n) * n;
                ((!mapped_count && 
                (approximation_address = (void *)((!h) * 
                (arena::getesp() + (5ull* 1024ull - hotness * 4ull)  * 1024ull * sizeof(char))))) 
                || (approximation_address = h));
            }
            template<class T>
			Arena<T>::Arena(const Arena& Arenains) throw() {
                size = Arenains.size;
                approximation_address = Arenains.approximation_address;
            }
            //template <class U>
            //  Arena<T>::Arena (const Arena<U>&) throw() {
            //}
            template<class T>
			Arena<T>::~Arena() throw() {
                
            }
            // return maximum number of elements that can be allocated
            template<class T>
            size_t Arena<T>::max_size () const throw() {
                return std::numeric_limits<std::size_t>::max() / sizeof(T);
            }
            // allocate but don't initialize num elements of type T
            template<class T>
            T* Arena<T>::allocate () {
                // print message and allocate memory with global new
                T* ret = NULL;
                if(mapped_but_notused){ 
                    for(std::vector<arena::Spanned_Address>::iterator it = Mapped_Address_Space.end() - 1; it != Mapped_Address_Space.begin() - 1 ; it--){
                        ret = (pointer)((unsigned long long)(it -> address) * (!it -> used) * (it -> size_spanned > size));
                        if(ret) {
                            own_address = ret;
                            size = it -> size_spanned;
                            it -> used = true;
                            pos = (it - Mapped_Address_Space.end()) + mapped_count;
                            mapped_but_notused--;
                            hint_address = (void *)((Mapped_Address_Space.end() - 1) -> address + (Mapped_Address_Space.end() - 1) -> size_spanned);
                            return ret;
                        }
                    }
                }
                std::cerr << "allocate " << size << " element(s)"
                          << " of size " << sizeof(T) << std::endl;
                ret = (pointer)::mmap(approximation_address,
                       size * sizeof(T),
                       PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS,
                       -1,
                       0);
                pos=mapped_count;
                mapped_count++;
                own_address = (void *)ret;
                Mapped_Address_Space.push_back({ own_address, true, size });
                hint_address = (void *)(ret + size * sizeof(T));
                std::cerr << " allocated at: " << (void*)ret << std::endl;
                return ret;
            }
            template<class T>
            T* Arena<T>::allocate (int previousDealloc) {
                // print message and allocate memory with global new
                if(!previousDealloc) return allocate();
                pos = previousDealloc - 1;
                pointer ret = (T*)Mapped_Address_Space[pos].address;
                Mapped_Address_Space[pos].used = true;
                mapped_but_notused--;
                return ret;
            }
            // initialize elements of allocated storage p with value value
            template<class T>
            void Arena<T>::construct (pointer p, const T& value) {
                // initialize memory with placement new
                new((void*)p)T(value);
            }
            // destroy elements of initialized storage p
            template<class T>
            void Arena<T>::destroy (pointer p) {
                // destroy objects by calling their destructor
                p->~T();
            }
            // deallocate storage p of deleted elements
            template<class T>
            void Arena<T>::deallocate () {
                Mapped_Address_Space[pos].used = false;
                mapped_but_notused++;
            }
            template<class T>
            void Arena<T>::flushArena(){
                for(auto&& it: Mapped_Address_Space){
                    ::munmap(it.address, it.size_spanned * sizeof(T));
                    std::cout << "OK OK don't yell i'm giving it back \n";
                }
                Mapped_Address_Space.resize(0);
                mapped_count = 0;
                mapped_but_notused = 0;
            }
            template<class T>
            inline void Arena<T>::generaldealloc(void* todealloc){
                for(auto&& it: Mapped_Address_Space){
                    if (it.address == todealloc && !(it.used=false) && ++mapped_but_notused) break;
                }
            }
            template<class T>
            inline void *Arena<T>::getHintAddress(){
                return hint_address;
            }
            template<class T>
            inline int Arena<T>::replacable(size_t n){
                deallocate(); return (n <= size) * (pos + 1);
            }

       // return that all specializations of this allocator are interchangeable
       template <class T1, class T2>
       bool operator== (const Arena<T1>&,
                        const Arena<T2>&) throw() {
           return true;
       }
       template <class T1, class T2>
       bool operator!= (const Arena<T1>&,
                        const Arena<T2>&) throw() {
           return false;
       }

struct HandleandNexthint
{
    void* handle;
    void* hint;
};

template <class T>
inline void allocateWithArena(size_t num, void* hint, unsigned long long hot, HandleandNexthint* hnn){
    Arena<T> HereAllocator(num,hint,hot);
    hnn->handle = HereAllocator.allocate(); hnn->hint = HereAllocator.getHintAddress();
}
template <class T>
inline void literal_flusher(){
    Arena<T> HereNth(0,0,0);
    HereNth.flushArena();
}
template <class T>
inline void deallochandle(void* tf){
    Arena<T> HereNth(0,0,0);
    HereNth.generaldealloc(tf);
}
template<typename T>
int Arena<T>::mapped_count = 0;
template<typename T>
int Arena<T>::mapped_but_notused = 0;
template<typename T>
std::vector<arena::Spanned_Address> Arena<T>::Mapped_Address_Space;
#endif
#endif
