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
        int n;
        cin >> n;
        vector<int> adj[n + 1];
        int degree[n + 1] = {0};
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        int ans = 0;
        int edge_number = n - 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=1;i<=n;i++) {
            if(degree[i] == 1) {
                pq.push(i);
            }
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int u = pq.top();
            pq.pop();
            ans = max(ans, u * edge_number);
            edge_number--;
            for (auto v : adj[u])
            {
                if (degree[v] > 1)
                {
                    degree[v]--;
                    if (degree[v] == 1)
                    {
                        pq.push(v);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}