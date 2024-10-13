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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }
        sort(vf(arr));
        int ans = arr[0];
        if (k == 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                ans = min(ans, arr[i + 1] - arr[i]);
            }
            cout << ans << endl;
            continue;
        }

        ans = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, arr[i + 1] - arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = arr[j] - arr[i];
                int ind = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                if (ind < n)
                    ans = min(ans, arr[ind] - x);
                if (ind > 0)
                    ans = min(ans, x - arr[ind - 1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}