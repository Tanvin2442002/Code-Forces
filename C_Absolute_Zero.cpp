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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool even = false, odd = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                even = true;
            }
            else
            {
                odd = true;
            }
        }
        if (even && odd)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;
        for (int i = 0; i < 40; i++)
        {
            sort(vf(arr));
            int a = arr[0];
            int b = arr[n - 1];
            int c = (a + b) / 2;
            ans.push_back(c);
            for (int j = 0; j < n; j++)
            {
                arr[j] = abs(arr[j] - c);
            }
        }
        sort(vf(arr));
        int a = arr[0];
        int b = arr[n - 1];
        if(a==b)
        {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            continue;
        }
        else
        {
            cout << -1 << endl;
            continue;
        }
    }
    return 0;
}