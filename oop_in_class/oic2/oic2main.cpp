#include<iostream>
#include "oic2.h"
#include "oic2x.h"
using namespace std;

int main()
{
    point p(2,2);
    vector v(3,3);
    p.settovector(v);
    return 0;
}