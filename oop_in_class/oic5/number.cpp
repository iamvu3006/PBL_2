#include"number.h"

number::number(int a):d(a)
{};

number::~number()
{

}

ostream &operator<<(ostream& os, const number &a)
{
    return os<<a;
}

number::operator int()
{
    return int(this->d);
}

number::operator double()
{
    return double(this->d);
}