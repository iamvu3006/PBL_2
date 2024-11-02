#include"point3d.h"
point3d :: point3d(int x, int y, int z):point(x,y)
{
    this->zval=z;
}

point3d::~point3d()
{
    cout<<"Huy point3d"<<endl;
}

void point3d::show3d()
{
    this->show();
    cout<<this->zval<<endl;
}

void point3d::show()
{
    cout<<this->xval<<","<<this->yval<<","<<this->zval<<endl;
}