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

bool f(const vector<int>&v, int k, int mid) {
  int n = v.size();
  vector<pair<int, int>> range = {{v[0] - mid, v[0] + mid}};
  for (int i = 1; i < n; ++i) {
    int low = max(v[i] - mid, range.back().first);
    int high = min(v[i] + mid, range.back().second);
    if (low > high) {
      if (k == 0)
        return false;
      --k;
      low = v[i] - mid;
      high = v[i] + mid;
    }
    range.push_back({low, high});
  }
  return true;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int lo = 0;
    int hi = 1e9;
    int ans = 0;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (f(v, k, mid)) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans <<endl;
  }
  return 0;
}
