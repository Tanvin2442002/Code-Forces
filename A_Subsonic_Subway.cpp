#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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
    int cs = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<float, float>> p(n);
        vector<float> ans;
        for (int i = 0; i < n; i++)
        {
            float x, y;
            cin >> x >> y;
            p[i] = {x, y};
            ans.push_back((float)(i + 1) / y);
        }
        float res = *max_element(vf(ans));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            float time = (float)(i + 1) / res;
            if (time >= p[i].first and time <= p[i].second)
            {
                cnt++;
            }
            // dbg(time, p[i].first, p[i].second);
        }
        if (cnt != n)
            cout << "Case #" << cs++ << ": " << -1LL << endl;
        else
            cout << "Case #" << cs++ << ": " << fixed << setprecision(6) << res << endl;
    }
    return 0;
}