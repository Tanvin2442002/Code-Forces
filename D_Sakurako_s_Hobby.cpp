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
        int n;
        cin >> n;
        string s;
        vector<int> v(n + 1);
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        cin >> s;
        // cout<<s<<endl;
        vector<int> ans(n + 1, 0);
        vector<int>cl;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            int j = v[i];
            int idx = i;
            if (!vis[i])
            {
                vis[i] = true;
                cl.push_back(i);
                while (j != idx)
                {
                    if (vis[j])
                    {
                        break;
                    }
                    vis[j] = true;
                    cl.push_back(j);

                    if (s[j - 1] == '0')
                    {
                        cnt++;
                    }
                    j = v[j];
                }
                if (s[j - 1] == '0')
                {
                    cnt++;
                }
                ans[i] = cnt;
                cout<<ans[i]<<" ";
                for(auto it:cl)
                {
                    ans[it]=cnt;
                }
                cl.clear();
            }
            else
            {
                cout<<ans[i]<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}