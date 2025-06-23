#pragma GCC optimize("O3")
#include <bits/stdc++.h>

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
ll inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      vector<int> x;
      for (int i = 0; i < m; i++) x.push_back(a[i]);
      sort(vr(x));
      ll tot = 0;
      for (int i = 0; i < m; i += 2) {
        int mx = x[i];
        if (i + 1 < m)
          mx = max(mx, x[i + 1]);
        tot += mx;
      }
      if (tot <= h)
        l = m;
      else
        r = m;
    }
    cout << l << endl;
  }
  return 0;
}
