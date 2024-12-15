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

float f(vector<pair<float, float>>& v, float mid) {
  int n = v.size();
  vector<float> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (v[i].first * mid + v[i].second);
  }
  return (*max_element(vf(a)) - *min_element(vf(a)));
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<float, float>> v(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v[i] = {x, y};
    }
    float lo = 0;
    float hi = k;
    while (hi-lo > 1e-9) {
      float mid1 = lo + (hi - lo) / 3.0;
      float mid2 = hi - (hi - lo) / 3.0;
      if (f(v, mid1) > f(v, mid2)) {
        lo = mid1;
      } else
        hi = mid2;
    }
    cout << fixed << setprecision(6) << f(v, lo) << endl;
  }
  return 0;
}