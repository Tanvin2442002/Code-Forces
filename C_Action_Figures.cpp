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
    string s;
    cin >> s;
    vector<int> v;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        v.push_back(i + 1);
      else
        a.push_back(i + 1);
    }
    reverse(vf(a));
    int ans = 0;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
      while (!v.empty() and v.back() >= i + 1) {
        v.pop_back();
      }
      while (!a.empty() and a.back() >= i + 1) {
        a.pop_back();
      }
      if (s[i] != '1')
        continue;
      if (v.size() > 0) {
        res.push_back(i + 1);
        v.pop_back();
      } else if (a.size() > 0) {
        res.push_back(i + 1);
        a.pop_back();
      }
    }
    cout << (n * (n + 1) / 2) - accumulate(vf(res), 0LL) << endl;
  }
  return 0;
}