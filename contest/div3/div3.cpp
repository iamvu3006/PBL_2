#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d, k, l, r, e = 0, f = 0;
        cin >> n >> d >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> l >> r;
            for (int i = l; i <= r; i++)
                a[i]++;
        }
        for (int i = 0; i < n; i++)
        {
            int max = a[i];
            if (a[i] > max)
            {
                max = a[i];
                e = i;
            }
            if (a[i] == max && i < e)
                e = i;
        }
        for (int i = 0; i < n; i++)
        {
            int min = a[i];
            if (a[i] < min)
            {
                min = a[i];
                f = i;
            }
            if (a[i] == min && i < f)
                f = i;
        }
        if(e - d >= 0)
        cout<<e;
        else
        cout<<1;
    }
    return 0;
}