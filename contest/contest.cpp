#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    ll t;
    cin >> t;
    vector<ll> res;
    while (t--)
    {
        ll n;
        cin >> n;
        ll *a, sum = 0;
        a = new ll[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (n < 3)
        {
            res.push_back(-1);
        }
        else
        {
            double ave;
            ave = (1.0) * sum / (2 * n);
            ll count = 0;
            for (ll i = 1; i <= n; i++)
            {
                if (a[i] < ave)
                    count++;
            }
            if (count > (n / 2))
            {
                res.push_back(0);
            }
            else if (count < (n / 2))
            {
                sort(a + 1, a + n);
                ll tmp = a[n / 2 + 1];
                ll x = (tmp * 2 * n - sum) + 1;
                res..push_back(x);
            }
        }
        delete[] a;
    }
    for (ll i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}