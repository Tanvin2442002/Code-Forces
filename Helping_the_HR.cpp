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
  // cin >> t;
  while (cin>>t) {
    if(t == 0) break;
    int n = t;
    int cnt = 0;
    while (n--) {
      string s;
      cin >> s;
      string init = "", fin = "";
      for (int i = 0; i < s.size() - 8; i++) {
        if (s[i] >= '0' && s[i] <= '9')
          init += s[i];
      }
      for (int i = s.size() - 8; i < s.size(); i++) {  // 173020-9
        if (s[i] >= '0' && s[i] <= '9')
          fin += s[i];
      }
      int a = stoi(init);
      int b = stoi(fin);
      // cerr << a << " " << b << endl;
      if (s[0] == 'D') {
        if (a <= 93000) {
          if (a <= 83000) {
            if (b - 83000 < 80000)
              cnt++;
          } else {
            if (b - a < 80000)
              cnt++;
          }
        } else {
          cnt++;
        }
        // cerr << cnt << endl;
      } else {
        if (a <= 123000) {
          if (a <= 83000) {
            a = 83000;
            if (b - a < 90000)
              cnt++;
          }
          else{
            if(b - a < 90000)cnt++;
          }
        } else
          cnt++;

        // cerr << cnt << endl;
      }
    }
    if (cnt == 0)
      cout << "All OK" << endl;
    else {
      if (cnt > 3)
        cout << "Issue Show Cause Letter" << endl;
      else {
        cout << cnt << " Point(s) Deducted" << endl;
      }
    }
  }
  return 0;
}
