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

vector<int> sums;

void build(vector<int>& a, int x, int lx, int rx) {
  if (lx == rx) {
    sums[x] = a[lx];
    return;
  }
  int m = (lx + rx) / 2;
  build(a, 2 * x, lx, m);
  build(a, 2 * x + 1, m + 1, rx);
  sums[x] = sums[2 * x] + sums[2 * x + 1];
}

void sett(int i, int v, int x, int lx, int rx) {
  if (lx > i or i > rx)
    return;
  if (rx == i and lx == i) {
    sums[x] = v;
    return;
  }
  int m = (lx + rx) / 2;
  sett(i, v, 2 * x, lx, m);
  sett(i, v, 2 * x + 1, m + 1, rx);
  sums[x] = sums[2 * x] + sums[2 * x + 1];
}

int query(int l, int r, int x, int lx, int rx) {
  if (lx > r or l > rx)
    return 0;
  if (lx >= l and rx <= r)
    return sums[x];

  int m = (lx + rx) / 2;
  int s1 = query(l, r, 2 * x, lx, m);
  int s2 = query(l, r, 2 * x + 1, m + 1, rx);
  return s1 + s2;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    sums.resize(4 * n + 5);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    build(v, 1, 1, n);
    while (m--) {
      int op;
      cin >> op;
      if (op == 1) {
        int i, v;
        cin >> i >> v;
        sett(i + 1, v, 1, 1, n);
      }
      if (op == 2) {
        int l, r;
        cin >> l >> r;
        cout << query(l+1, r, 1, 1, n) << endl;
        ;
      }
    }
  }
  return 0;
}