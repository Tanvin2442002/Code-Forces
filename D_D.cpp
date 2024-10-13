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
    // cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        set<int> digits;
        for (int i = 0; i < k; i++)
        {
            int d;
            cin >> d;
            digits.insert(d);
        }
        for (int i = n;; i++)
        {
            string s = to_string(i);
            bool valid = true;
            for (auto c : s)
            {
                if (digits.count(c - '0') > 0)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}