#include <iostream>

using namespace std;

class matrix
{
private:
    int **p;
    int col, row;

public:
    matrix(int, int);
    friend ostream &operator<<(ostream &, const matrix &);
    friend istream &operator>>(istream &, matrix &);
    int& operator ()(int &,int &);
    ~matrix();
};