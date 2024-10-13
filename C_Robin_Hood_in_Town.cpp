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

int mx = 1e9 + 7;
int mn = 0;

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        float avg = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            avg += v[i];
        }
        if (n == 1 or n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        sort(vf(v));
        avg = avg/(float)n;
        avg = avg/(float)2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] < avg)
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            cout << 0 << endl;
        }
        else
        {
            int mid;

            mid = n / 2;

            int ans = v[mid];
            ans *= 2;
            ans *= n;
            for (int i = 0; i < n - 1; i++)
            {
                ans -= v[i];
            }
            cout << ans - v[n - 1] + 1 << endl;
        }
    }
    return 0;
}