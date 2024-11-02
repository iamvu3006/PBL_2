#include <iostream>
using namespace std;
class vector
{
private:
    float x;
    float y;

public:
    vector(int, int);
    friend void point::settovector(vector &);
};