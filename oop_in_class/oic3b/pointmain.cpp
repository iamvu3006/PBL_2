#include"point.h"

int main()
{
    point a(1,2);point b(1,2);
    point c=a++;
    point d=++b;
    cout<<a<<b;
    return 0;   
}