#include <iostream>

using namespace std;
class number
{
private:
    int d;
public:
    number(int);
    ~number();
    friend ostream &operator<<(ostream&, const number &);
    friend istream &operator>>(istream&, number &);
    operator int();
    operator double();
};