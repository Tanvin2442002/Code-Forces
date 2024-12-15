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

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]]++;
    }
    bool f = false;
    for (auto i : mp) {
      if (i.second < 2) {
        f = true;
        break;
      }
    }
    if (f)
      cout << -1 << endl;
    else {
      vector<int> id(n);
      iota(vf(id), 1);
      for (int i = 0; i < n; i++) {
        if (i < n - 1 and v[i] == v[i + 1]) {
          swap(id[i], id[i + 1]);
          f = true;
        }
      }
      for (auto i : id) cout << i << " ";
      cout << endl;
    }
  }
  return 0;
}