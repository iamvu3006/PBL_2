#include <iostream>
#include "oic2.h"
using namespace std;

class vector;

void point::show()
{
   cout<<this->xval<<" "<<this->yval;
}

point::point(int x,int y)
{
   this->xval=x;
   this->yval=y;
}

void point::settovector(vector& x)
{
   this->xval=x.x;
   this->xval=x.y;
}