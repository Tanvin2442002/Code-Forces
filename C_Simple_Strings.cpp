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
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        int a = s[i - 1];
        int b;
        if (i + 1 < s.size()) {
          b = s[i + 1];
        } else
          b = a;
        int c = abs(a - b);
        int d = 0;
        if (c == 0)
        {
           d = a + 1;
           if(char(d)>'z'){
             d = a - 1;
           }
        }
        else if (c == 1)
        {
            d = max(a,b)+1;
            if(char(d)>'z'){
              d = min(a,b) - 1;
            }
        }
        else
          d = min(a, b) + 1;
        s[i] = char(d);
      }
    }
    cout << s << endl;
  }
  return 0;
}