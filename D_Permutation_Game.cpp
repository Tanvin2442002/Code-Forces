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
        int n, k, pb, ps;
        cin >> n >> k >> pb >> ps;
        vector<int> p(n + 1);
        vector<int> a(n + 1);
        int index = 0, mx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > mx)
            {
                mx = a[i];
                index = i;
            }
        }
        int bodya = k * a[pb], sasha = k * a[ps];
        int cnt = 0;
        int temp_score = 0;
        int rem = 0;
        while (pb != index)
        {
            temp_score += a[pb];
            cnt++;
            if (pb == p[pb])
                break;
            pb = p[pb];
            rem = max(0LL, k - cnt);
            bodya = max(bodya, temp_score + rem * a[pb]);
            if (cnt == k or cnt > n)
                break;
        }
        rem = max(0LL, k - cnt);
        bodya = max(bodya, temp_score + rem * a[pb]);
        cnt = 0, temp_score = 0;
        rem = 0;
        while (ps != index)
        {
            temp_score += a[ps];
            cnt++;
            if (ps == p[ps])
                break;
            ps = p[ps];
            rem = max(0LL, k - cnt);
            sasha = max(sasha, temp_score + rem * a[ps]);
            if (cnt == k or cnt > n)
                break;
        }
        rem = max(0LL, k - cnt);
        sasha = max(sasha, temp_score + rem * a[ps]);
        if (sasha > bodya)
            cout << "Sasha" << endl;
        else if (sasha == bodya)
            cout << "Draw" << endl;
        else
            cout << "Bodya" << endl;
    }
    return 0;
}