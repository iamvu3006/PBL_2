#include"date.h"

int main()
{
    date a(50,50,6);
    date b(10,10,10);
    date c=b++;
    date d=++b;
    date e=b--;
    date z=--b;
    a+=10;
    cout<<d<<endl<<e<<endl<<z<<endl;
    return 0;
}