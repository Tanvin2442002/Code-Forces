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

int mod = 1000000007;
ll inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n), b(m);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int j = 0; j < m; j++) {
      cin >> b[j];
    }
    sort(vf(b));
    ll lo = -inf;
    ll last = lo;
    bool f = true;
    for (int i = 0; i < n; i++) {
      ll unchanged = inf;
      if (v[i] >= last)
        unchanged = v[i];        
      ll needed = last + v[i];
      ll changed = inf;
      int idx = lower_bound(vf(b), needed)-b.begin();
      if(idx<m){
        changed = b[idx]-v[i];
      }
      ll p = min(unchanged, changed);
      if (p == inf) {
        f = false;
        break;
      }
      last = p;
    }
    
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
