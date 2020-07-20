#include "Window.h"    
    Window::Window(const char* str, bool f){
        p_label = (char *)str;
        width = 640; height = 480; flag = SDL_WINDOW_SHOWN;
        p_renderer = NULL; screen = NULL; fullscreen = f;
    }
    Window::Window(SingleUseString* pstr, bool f){
        int length = pstr ->getLen();
        p_label = (char *)malloc(length*sizeof(char));
        for(int i = 0; i < length; i++){
            *(p_label + i) = pstr ->getchar(i);
        }
        width = 640; height = 480; flag = SDL_WINDOW_SHOWN;
        p_renderer = NULL; screen = NULL; fullscreen = f;
    }
    void Window::initWindow(int w, int h, Uint32 f){
        width = w;
        height = h;
        flag = f;
        screen = SDL_CreateWindow(p_label,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          w, h,
                          f|(fullscreen*SDL_WINDOW_FULLSCREEN));
        p_renderer = (SDL_Renderer**)malloc(sizeof(SDL_Renderer*));
        *p_renderer = SDL_CreateRenderer(screen, -1, 0);

        SDL_SetRenderDrawColor(*p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(*p_renderer);
        SDL_RenderPresent(*p_renderer);
    }
    void Window::initWindow(Uint32 f){
        flag = f;
        screen = SDL_CreateWindow(p_label,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          width, height,
                          f|(fullscreen*SDL_WINDOW_FULLSCREEN));
        p_renderer = (SDL_Renderer**)malloc(sizeof(SDL_Renderer*));
        *p_renderer = SDL_CreateRenderer(screen, -1, 0);

        SDL_SetRenderDrawColor(*p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(*p_renderer);
        SDL_RenderPresent(*p_renderer);
    }
    void Window::initWindow(){
        screen = SDL_CreateWindow(p_label,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          width, height,
                          flag|(fullscreen*SDL_WINDOW_FULLSCREEN));
        p_renderer = (SDL_Renderer**)malloc(sizeof(SDL_Renderer*));
        *p_renderer = SDL_CreateRenderer(screen, -1, 0);

        SDL_SetRenderDrawColor(*p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(*p_renderer);
        SDL_RenderPresent(*p_renderer);
    }
    void Window::clearWindow(){
        (!p_renderer||!screen) ? (bool)(std::cout << "Try Initializing the Window!" << std::endl) : 1;
        SDL_SetRenderDrawColor(*p_renderer, 0, 0, 0, 255);
        SDL_RenderClear(*p_renderer);
        SDL_RenderPresent(*p_renderer);
    }
    void Window::clearWindow(int r, int g, int b, int a){
        (!*p_renderer||!screen) ? (bool)(std::cout << "Try Initializing the Window!" << std::endl) : 1;
        SDL_SetRenderDrawColor(*p_renderer, r, g, b, a);
        SDL_RenderClear(*p_renderer);
        SDL_RenderPresent(*p_renderer);
    }
    int Window::getHeight(){
        return height;
    }
    int Window::getWidth(){
        return width;
    }
    SingleUseString* Window::getLabel(){
        SingleUseString* retStr = new SingleUseString(p_label);
        return retStr;
    }
    void Window::setFullscreen(bool f){
        fullscreen = f;
    }
    void Window::render(){
        SDL_RenderPresent(*p_renderer);

        SDL_RenderClear(*p_renderer);
    }
    SDL_Renderer** Window::getRendererPointer(){
        return p_renderer;
    }