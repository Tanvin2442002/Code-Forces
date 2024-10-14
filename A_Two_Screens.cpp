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
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    int i = 0;
    int sz = max(s.size(), t.size());
    while (true) {
      if (s[i] == t[i]) {
        i++;
        cnt++;
      } else
        break;
      if (i == sz)
        break;
    }
    int op = cnt + (s.size() - cnt) + (t.size() - cnt);
    if (cnt > 0)
      cout << op + 1 << endl;
    else
      cout << op << endl;
  }
  return 0;
}