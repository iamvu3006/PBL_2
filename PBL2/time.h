#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include "event.h"
using namespace std;

class thoigian
{
private:
    int year, month, day, hour, minute, second;
public:
    thoigian();
    thoigian(int, int, int, int, int, int);
    friend istream &operator>>(istream &, thoigian &);
    friend ostream &operator<<(ostream &, const thoigian &);
    bool operator==(const thoigian &);
};