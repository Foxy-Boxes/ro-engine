#include <ctime>

class Time{
public:
    Time(double);
    double getTimepassed_from(time_t);
    time_t start();
    long double update();
    double getDelta();
    bool frame();
    void setFrameRate(double);
};
