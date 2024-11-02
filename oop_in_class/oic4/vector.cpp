#include "vector.h"
vector::vector(int x)
{
    this->n = x;
    if (n == 0)
    {
        this->p = nullptr;
    }
    else
    {
        this->p = new int[this->n];
        cin>>(*this);
    }
}

vector::vector(const vector &v)
{
    this->p = NULL;
    this->n = v.n;
    this->p = new int[this->n];
    cin >> (*this);
}

vector::~vector()
{
    delete[] p;
}

istream &operator>>(istream &is, vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        is >> v[i];
    }
    return is;
}


ostream &operator<<(ostream &os, const vector &v)
{
    for (int i = 0; i < v.n; i++)
    {
        os << *(v.p+i);
    }
    return os;
}

int &vector::operator[](const int &i)
{
    static int tmp = 0;
    if (i > 0 && i < this->n)
        return *(this->p + i);
    else
        return tmp;
}