#include <iostream>
using namespace std;

class vector
{
private:
    int *p;
    int n;

public:
    vector(int = 0);
    vector(const vector &);
    ~vector();
    friend istream &operator>>(istream &, vector &);
    friend ostream &operator<<(ostream &, const vector &);
    int& operator[](const int &);
};