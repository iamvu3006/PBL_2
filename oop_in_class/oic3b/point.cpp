#include "point.h"

point::point(int xval, int yval)
{
    this->xval = xval;
    this->yval = yval;
}

void point::show()
{
    cout << this->xval << " " << this->yval << endl;
}

point operator+(const point &p1, const point &p2)
{
    point p(p1.xval + p2.xval, p1.yval + p2.yval);
    return p;
}

point::point(const int& x): xval(x), yval(x)
{}

point point::operator-(const point &q)
{
    point p(this->xval - q.xval, this->yval - q.yval);
    return p;
}

// point point::operator+(int x)
// {
//     return (this->xval+x,this->yval+x);
// }

istream &operator>>(istream &is,  point &p)
{
    return is >> p.xval >> p.yval;
}

ostream &operator<<(ostream &os, const point &p)
{
    return os << p.xval << p.yval;
}

point point::operator++()
{
    this->xval++;
    this->yval++;
    return *(this);
}

const point point::operator++(int)
{
    point bef = (*this);
    (*this)++;
    return bef;
}



int main()
{
    point p1(9, 8);
    point p2(6, 7);
    point p3 = p1.operator-(p2);
    p3.show();
    point p4 = operator+(p1, p2);
    p4.show();
    point p5 = 3+p1;
    p5.show();
    cin >> p1;
    cout << p1;
    return 0;
}