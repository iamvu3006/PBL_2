#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
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

#endif // TIME_H