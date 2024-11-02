#include <iostream>
#include "oic2x.h"
using namespace std;

class vector;
class point
{
private:
    int xval;
    int yval;

public:
    point(int,int);
    void settovector(vertor&);
    void show();
};