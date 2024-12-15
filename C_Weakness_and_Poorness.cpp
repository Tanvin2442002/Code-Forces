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

double eps = 1e-12;

float f(vector<int>& v, float x) {
  float mn = 0, mx = 0, ans1 = 0, ans2 = 0;
  for (int i = 0; i < v.size(); i++) {
    ans1 += (v[i] - x);
    mx = max(mx, ans1);
    mn = min(mn, ans1);
    ans2 = max({ans2,abs(ans1 - mn),abs(ans1 - mx)});
  }
  return ans2;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    float l = -1e4, r = 1e4;
    while (r - l > eps) {
      float mid1 = l + (r - l) / 3.0;
      float mid2 = r - (r - l) / 3.0;
      if (f(v, mid1) > f(v, mid2)) {
        l = mid1;
      } else
        r = mid2;
    }
    cout << fixed << setprecision(10) << f(v, l) << endl;
  }
  return 0;
}