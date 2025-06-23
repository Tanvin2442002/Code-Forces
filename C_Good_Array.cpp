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
    int n;
    cin >> n;
    vector<ll> v(n);
    map<ll, vector<ll>> mp;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]].push_back(i + 1);
    }
    ll s = accumulate(vf(v), 0LL);
    vector<int> result;
    for (int i = 0; i < n; i++) {
      ll tmp = s - v[i];
      tmp -= v[i];
      if (tmp != v[i]) {
        if (mp[tmp].size() > 0) {
          while (mp[tmp].size() > 0) {
            result.push_back(mp[tmp].back());
            mp[tmp].pop_back();
          }
        }
      } else {
        if (mp[tmp].size() > 1) {
          while (mp[tmp].size() > 0) {
            result.push_back(mp[tmp].back());
            mp[tmp].pop_back();
          }
        }
      }
    }
    cout << result.size() << endl;
    for (auto i : result) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}