#include <ctime>
#include "Time.h"

        /* Time is working but we may add some sort of sleep functionality*/ 
        /* data */
        double framerate;// effectively you can use this as a framecap.
        double delta;
        clock_t startClock;
        long double unprocessed;
        Time::Time(register double fr){
            framerate = fr;
            delta = (double)1/fr;
            startClock = clock();
            unprocessed = 0;
        }
        double Time::getTimepassed_from(time_t lastclock){
            return (double)(clock() - lastclock)/CLOCKS_PER_SEC;
        }
        time_t Time::start(){
            /*Use this before gameloop*/
            startClock = clock();
            unprocessed = 0;
            return startClock;
        }
        long double Time::update(){
            /*This method returns time passed*/
            clock_t sc = startClock;
            startClock = clock();
            long double time_passed = (long double)(startClock - sc)/(long double)CLOCKS_PER_SEC;
            unprocessed += time_passed;
            return time_passed;
        }
        double Time::getDelta(){
            return delta;
        }
        bool Time::frame(){
            long double unprocessed_last = unprocessed;
            unprocessed -= (unprocessed_last > delta)*delta;
            return unprocessed_last > delta;
        }
        void Time::setFrameRate(double fr){
            framerate = fr;
            delta = (double)1/fr;
        }
