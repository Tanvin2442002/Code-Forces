#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

vector<int> depth;

class TreeAncestor {
  vector<vector<int>> up;
  int LOG;
public:
  TreeAncestor(int n, vector<int>& parent) {
    LOG = 0;
    while ((1 << (LOG + 1)) <= n) {
      LOG++;
    }
    LOG++;
    up = vector<vector<int>>(n + 1, vector<int>(LOG));
    depth = vector<int>(n + 1);
    parent[1] = 1; 
    for (int v = 1; v <= n; v++) {
      up[v][0] = parent[v];
      if (v != 1) {
        depth[v] = depth[parent[v]] + 1;
      }
      for (int j = 1; j < LOG; j++) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    if (depth[node] < k) return -1;
    for (int j = 0; j < LOG; j++) {
      if (k & (1 << j)) {
        node = up[node][j];
      }
    }
    return node;
  }
};

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1);
    for (int i = 2; i <= n; i++) {
      cin >> parent[i];
    }
    TreeAncestor T(n, parent);
    while (q--) {
      int v, k;
      cin >> v >> k;
      int ans = T.getKthAncestor(v, k);
      cout << ans << endl;
    }
  }
  return 0;
}
