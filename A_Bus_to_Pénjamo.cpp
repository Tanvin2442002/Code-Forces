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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {

            ans += ((a[i] / 2) * 2);

            if (a[i] % 2 == 1)
                cnt++;
        }
        // cerr << cnt << endl;
        int res = 2 * m - ans;
        // cerr << res << endl;
        if (res == cnt)
        {
            cout << ans << endl;
        }
        else
        {
            int x = res / 2;
            if (x > cnt)
            {
                cout << ans + cnt << endl;
            }
            else
            {
                int y = cnt % x;
                cout << ans + (x - y) << endl;
            }
        }
    }
    return 0;
}