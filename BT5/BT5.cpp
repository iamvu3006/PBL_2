#include <iostream>
#include <ctime>
#include "BT5.h"

using namespace std;

void time::current_time()
{
    this->current = time(nullptr);
    loc_time = localtime(&current);
}

void time::start()
{
    this->start = time(nullptr);
    tm *localtime = localtime(&start)
}

void time::take_time()
{
    int n;
    cout<<"Nhap khoang thoi gian can: ";
    this_thread::sleep_for(chrono::minutes(n));
    this->end = time(nullptr);
}

void time::calc()
{
    this->abtime = difftime(this->end,this->start);
}

void time::setting(int n)
{
    switch(n)
    {
        case 1:
            current = time(nullptr);
        case 2:
            tm* localtime = localtime(current);
        case 3:
            tm* gmt
    }

}