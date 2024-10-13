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
        int b, c, d;
        cin >> b >> c >> d;
        int a = (b | d) & (~c);
        if ((a | b) - (a & c) == d and a <= (1LL << 61))
        {
            cout << a << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}