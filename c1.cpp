#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
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
    map<int, vector<int>> mp, pref;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      mp[x].push_back(i);
      if (pref[x].empty()) {
        pref[x].push_back(i);
      } else
        pref[x].push_back(pref[x].back() + i);
    }
    dbg(pref);
    int ans = 0;
    for (auto &it : mp) {
      int num = it.first;
      for (auto i : it.second) {
        if (mp.count(-num) == 0)
          continue;
        int ind = upper_bound(mp[-num].begin(), mp[-num].end(), i) - mp[-num].begin();
        if(ind == mp[-num].size())
          continue;
        int cnt = mp[-num].size() - ind;
        dbg(num, i, ind, cnt);
        ans += (n * cnt) - (pref[-num].back() - pref[-num][max(ind - 1, 0LL)]);


        ind = upper_bound(mp[num].begin(), mp[num].end(), ind) - mp[num].begin();
        if(ind == mp[num].size())
          continue;
        cnt = mp[num].size() - ind;
        // dbg(num, i, ind, cnt);
        ans -= (cnt);
        
      }
    }
    cout << ans << '\n';
  }
  return 0;
}