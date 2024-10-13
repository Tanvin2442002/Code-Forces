#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;
                    
int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        if (m == 1)
        {
            if (n == 0)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            if (n != 0)
            {
                cout << (1LL << m) - 1 << endl;
            }
            else
                cout << (1LL << m) << endl;
        }
    }
    return 0;
}