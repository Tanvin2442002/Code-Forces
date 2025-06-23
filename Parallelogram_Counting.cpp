#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1e9 + 7;
ll inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  int cs = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }
    vector<pair<int, int>> mids;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        mids.push_back({v[i].first + v[j].first, v[i].second + v[j].second});
      }
    }
    int ans = 0;
    sort(vf(mids));
    // dbg(mids);
    ll c = 1;
    for (int i = 0; i < mids.size() - 1; i++) {
      if (mids[i] == mids[i + 1])
        c++;
      else {
        ans += (c * (c - 1)) / 2;
        c = 1;
      }
    }
    ans += (c * (c - 1)) / 2;
    cout << "Case " << cs++ << ": " << ans << '\n';
  }
  return 0;
}