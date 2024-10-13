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
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> prefix(n);
        partial_sum(arr.begin(), arr.end(), prefix.begin());
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << prefix[i] << ' ';
        // }
        // cerr << endl;
        int i = 0;
        int cnt = 0;
        int tmp = 0;
        while (i < n)
        {
            int idx = upper_bound(vf(prefix), l + tmp) - prefix.begin();
            if (idx != 0)
            {
                if (prefix[idx - 1] >= l + tmp)
                {
                    idx--;
                }
            }
            // cerr << idx << endl;
            if (idx < n)
            {
                if (prefix[idx] - tmp >= l and prefix[idx] - tmp <= r)
                {
                    cnt++;
                    tmp = prefix[idx];
                    i = idx;
                }
                else
                {
                    tmp = prefix[i];
                    i++;
                }
            }
            else
            {
                break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}