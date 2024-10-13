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
        int n;
        cin >> n;
        vector<int> v(n), p(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int k = 1;
        int i = k - 1;
        int j = k + 1;
        while (k < n - 1)
        {
            while (i >= 0 and j <= n - 1)
            {
                int x = min((v[k] - v[i]), (v[k] - v[j]));
                if (p[k] <= x)
                {
                    p[k] = x;
                }
                i--;
                j++;
            }
            k++;
            i = k - 1;
            j = k + 1;
        }
        cout << *max_element(vf(p)) << endl;
    }
    return 0;
}