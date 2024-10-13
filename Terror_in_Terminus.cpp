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
const int MAXN = 100000;
const int LOG = 17;

vector<int> adj[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int dist[MAXN];

void dfs(int v, int p)
{
    up[v][0] = p;
    for (int i = 1; i < LOG; i++)
    {
        if (up[v][i - 1] != -1)
        {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
        else
        {
            up[v][i] = -1;
        }
    }

    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dist[u] = dist[v] + 1;
            dfs(u, v);
        }
    }
}
int dsu(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v])
        {
            u = up[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int mid(int u, int v)
{
    int ancestor = dsu(u, v);
    int total = depth[u] + depth[v] - 2 * depth[ancestor];
    int midpoint = total / 2;
    if (depth[u] - depth[ancestor] >= midpoint)
    {
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (midpoint >= (1 << i))
            {
                u = up[u][i];
                midpoint -= (1 << i);
            }
        }
        return u;
    }
    else
    {
        midpoint = total - midpoint;
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (midpoint >= (1 << i))
            {
                v = up[v][i];
                midpoint -= (1 << i);
            }
        }
        return v;
    }
}

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
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            for (int j = 0; j < LOG; j++)
            {
                up[i][j] = -1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth[0] = 0;
        dist[0] = 0;
        dfs(0, -1);

        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            int result = mid(u, v);
            cout << result + 1 << endl;
        }
    }
    return 0;
}