#include <bits/stdc++.h>
#include "try.h"

using namespace std;

int main()
{
    int a[1000];
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        sinhvien a[i];
        a[i].nhap();
        a[i].xuat();
    }
    return 0;
}