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
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> mp;
    map<int, int> mpleft;
    map<int, int> mpright;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
      mpleft[v[i]]++;
      mpright[v[i]]++;
    }
    int idx1;
    for (int i = 0; i < n; i++) {
      if (v[i] == k) {
        idx1 = i;
        break;
      }
    }
    int idx2 = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (v[i] == k) {
        idx2 = i;
        break;
      }
    }
    int mx = 0;
    for (auto i : mp) {
      mx = max(mx, i.second);
    }
    if (mx <= mp[k]) {
      cout << 0 << endl;
      continue;
    }
    bool one = false;
    for (int i = 0; i < idx2; i++) {
      // mp[v[i]]--;
      mpleft[v[i]]--;
      int mx = 0;
      for (auto i : mpleft) {
        mx = max(mx, i.second);
      }
      if (mx <= mpleft[k]) {
        one = true;
        break;
      }
    }
    if (one) {
      cout << 1 << endl;
      continue;
    }
    bool two = false;
    for (int i = n - 1; i > idx1; i--) {
        // mp[v[i]]--;
        mpright[v[i]]--;
        int mx = 0;
        for (auto i : mpright) {
          mx = max(mx, i.second);
        }
        if (mx <= mpright[k]) {
          two = true;
          break;
        }
    }
    if (two)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
  return 0;
}