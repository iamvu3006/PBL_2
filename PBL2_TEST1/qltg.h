#ifndef QLTG_H
#define QLTG_H

#include <iostream>
#include <vector>
#include "time.h"
#include "event.h"
using namespace std;

class qltg
{
private:
    vector<Event> events;

public:
    void print();
    void add();
    void erase();
    void fix();
};

#endif  // QLTG_H