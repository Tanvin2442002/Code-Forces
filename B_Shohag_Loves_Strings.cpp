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
    string s;
    cin >> s;
    int cnt = 0;
    int cntsame = 0;
    string temp = "";
    bool flag = false;
    for (int i = 0;i< s.size() - 1; i++) {
      if (s[i] == s[i + 1]) {
        cout << s[i] << s[i + 1] << endl;
        flag = true;
        // cout<<flag<<endl;
        break;
      }
    }
    // dbg(flag);
    if (!flag) {
      if (s.size() >= 3) {
        for (int i = 0; i < s.size() - 2; i++) {
          if ((s[i] != s[i + 1]) and (s[i + 1] != s[i + 2]) and (s[i]!=s[i+2])) {
            cout << s[i] << s[i + 1] << s[i + 2] << endl;
            flag = true;
            break;
          }
        }
      }
    }
    if (!flag)
      cout << -1 << endl;
  }
  return 0;
}