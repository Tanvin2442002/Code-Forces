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
//  #include <ext/pb_ds/assoc_container.hpp>

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
        int a, b;
        cin >> a >> b;
        if (a % 2 == 1)
            cout << "NO" << endl;
        else
        {
            if (a == 0)
            {
                if (b % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else if (b == 0)
            {
                if (a % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
            else
            {
                int ans = a;
                ans += b * 2;
                if (ans % 2 == 0)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}