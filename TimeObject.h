#ifndef TIMEOBJECT_H
#define TIMEOBJECT_H
#include <time.h>
#include <inttypes.h>



class TimeObject
{
    public:
       double pcf = 0.0;
       __int64 counter_start = 0;

       void start_timer();
       double get_timer();
};

#endif // TIME_H
