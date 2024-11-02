#include <iostream>
using namespace std;
class point
{
protected:
    int xval;
    int yval;

public:
    point(int , int );
    point(const int&);
    void show();
    friend point operator+(const point &, const point &);
    friend istream &operator>>(istream &,  point &);
    friend ostream &operator<<(ostream &, const point &);
    point operator-(const point &);
    const point operator++(int);
    point operator++();
    // point operator+(int);
};