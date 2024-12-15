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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> suffix(n);
    (s[n - 1] == '0') ? suffix[n - 1] = -1 : suffix[n - 1] = 1;
    // dbg(suffix);
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '0')
        suffix[i] = suffix[i + 1] - 1;
      else
        suffix[i] = suffix[i + 1] + 1;
    }
    suffix.erase(suffix.begin());
    sort(vf(suffix));
    reverse(vf(suffix));
    dbg(suffix);
    int ans = 0;
    bool f = false;
    int id = 0;
    for (int i = 0; i < n - 1; i++) {
      ans += suffix[i];
      if (ans >= k) {
        f = true;
        id = i + 2;
        break;
      }
    }
    if (f)
      cout << id << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}