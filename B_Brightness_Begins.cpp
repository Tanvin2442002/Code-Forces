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
int inf = 2e18;

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int n = k;
        int l = k, r = inf;
        int ans = 0;
        while(l <= r){
            int m = l + (r-l)/2;
            // cerr<<m<<endl;
            if (m - sqrt(m) <= k)
            {
                ans = m;
                // cerr<<ans<<endl;
                l = m + 1;
            }
            else if (m - sqrt(m) > k)
            {
                r = m - 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}