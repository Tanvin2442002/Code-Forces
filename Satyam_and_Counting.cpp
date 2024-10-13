#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "F:\debug.hpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

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
        int n;
        cin >> n;
        map<pair<int, int>, int> mp;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            arr[i] = {x, y};
            mp[{x, y}] = 1;
        }
        sort(vf(arr));
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i].first == arr[i + 1].first )
            {
                cnt++;
            }
        }
        ans += (cnt * (n - 2));
        for (int i = 0; i < n; i++)
        {
            int x = arr[i].first;
            int y = arr[i].second;
            if (mp[{x + 2, y}] == 1 and mp[{x + 1, y - 1}] == 1 )
            {
                ans++;
            }
            if (mp[{x + 2, y}] == 1 and mp[{x + 1, y + 1}] == 1 )
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}