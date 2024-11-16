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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    vector<bool> v(n + 1, false);
    for (int i = 0; i < n; i++) {
      if (a[i] <= n)
        v[a[i]] = true;
    }
    vector<int> mex;
    for (int i = 0; i < v.size(); i++) {
      if (!v[i]) {
        mex.push_back(i);
      }
    }
    sort(vf(mex));
    for (auto i : mp) {
      if (i.second > 1) {
        int z = i.second - 1;
        mp[i.first] = 1;
        mp[i.first + x] += z;
      }
    }
    for (int i = 0; i < mex.size(); i++) {
      if (mp[mex[i]] == 0) {
        cout << mex[i] << "\n";
        break;
      }
    }
  }
  return 0;
}