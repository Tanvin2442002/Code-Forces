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
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]].push_back(i);
    }
    int ans = 0;
    for (auto &it : mp) {
      int num = it.first;
      // dbg("------");
      if (mp.count(-num)) {
        // dbg(num);
        // dbg(num, mp[num]);
        // dbg(-num, mp[-num]);
        for (auto i : it.second) {
          int idx = upper_bound(vf(mp[-num]), i) - mp[-num].begin();
          if (idx == mp[-num].size())
            continue;
          int N = mp[-num].size();
          for (int j = idx; j < N; j++) {
            int value = mp[-num][j];
            int add = 0;
            if (value < n - 1) {
              // dbg("Checking", i, value);
              add += (n - 1 - value);
              // dbg("1", add);
              int posSize = mp[num].size();
              int negSize = mp[-num].size();
              int posj = upper_bound(vf(mp[num]), value) - mp[num].begin();
              // int negj = upper_bound(vf(mp[-num]), value) - mp[-num].begin();
              // dbg(j, value, posSize, posj, negSize);
              add -= (posSize - posj);
              // dbg("plus ase", posSize, posj, posSize - posj);
              // dbg("2", add);
              // add -= (negSize - negj);
              if(num != 0)
              add -= (negSize - 1 - j);
              // dbg("minus ase", negSize, j, negSize - 1 - j);
              // dbg("3", add);
            }
            // dbg("Add", add);
            ans += add;
          }
        }
      }
      // dbg(num, ans);
    }
    cout << ans << endl;
  }
  return 0;
}