#pragma once
#include "time.h"
using namespace std;

class qltg
{
public:
    vector<Event> time;
    void add(vector<Event> &);
    void erase(vector<Event> &);
    void print(const vector<Event> &);
    void fix(vector<Event> &);
};