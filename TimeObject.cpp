#include "TimeObject.h"
#include <time.h>
#include <windows.h>
#include <inttypes.h>
#include <iostream>

using namespace std;

void TimeObject::start_timer(){  // sets start point for timer
        LARGE_INTEGER li;
        if(!QueryPerformanceFrequency(&li)){
            cout<<"QueryPerformanceFrequency failed!"<<endl;
        }
        pcf = double(li.QuadPart)/1000.0;
        QueryPerformanceCounter(&li);
        counter_start = li.QuadPart;
    }

double TimeObject::get_timer(){  // gets timer value since the last call of start_timer()
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return double(li.QuadPart-counter_start)/pcf;
    }

