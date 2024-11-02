#include <iostream>
#include "oic.h"

using namespace std;

int point::n = 0;

point::point(int xval,int y)
    ::xval(5),yval(6),m(9)
    
{
    this->xval  = xval; this->yval=yval;
    point::n++
}

point::~point(const point& p)
    ::m(p,m)
    {
        this->xval = p.xval;
        this->yval = p.yval;
        point::n--;
    }

void::point::count()
{
    cout<<point::n<<endl;
}

void point::show()
{
    cout<<this->xval<<" "<<this->val<<endl;
    cout<<this->m<<endl;
}