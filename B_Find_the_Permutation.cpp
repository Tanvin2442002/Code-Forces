#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define ll long long
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

vector<vector<int>> adjacencyListFromMatrix(const vector<string> &matrix, int n) {
  vector<vector<int>> adjacencyList(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '1') {
        if (i < j)
          adjacencyList[i].push_back(j + 1);
        else
          adjacencyList[j].push_back(i + 1);
      }
    }
  }
  return adjacencyList;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> degree;
    vector<vector<int>> adj(n + 5);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        char x;
        cin >> x;
        if (x == '1') {
          if (i <j) {
            adj[i].push_back(j);
          } else {
            adj[j].push_back(i);
          }
        }
      }
    }
    dbg(adj);
    vector<bool> visited(n + 5, 0);
    vector<int> ans;
    function<void(int)> dfs = [&](int v) {
      visited[v] = true;
      for (int u : adj[v]) {
        if (!visited[u])
          dfs(u);
      }
      ans.push_back(v);
    };
    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";
    cout << endl;
  }

  return 0;
}
