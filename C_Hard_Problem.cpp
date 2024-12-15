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
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int row1 = 0;
    if (m <= a) {
      row1 = m;
    } else {
      row1 = a;
      int diff = m - a;
      if (c >= diff) {
        row1 += m - a;
        c -= (m - a);
      }
      else {
        row1+=c;
        c = 0;
      }
    }
    // cerr<<row1<<endl;
    int row2 = 0;
    if (m <= b) {
      row2 = m;
    } else {
      row2 = b;
      int diff = m - b;
      if (c >= diff) {
        row2 += m - b;
        c -= (m - b);
      }else{
        row2+=c;
        c = 0;
      }
    }
    cout << row1 + row2 << endl;
  }
  return 0;
}