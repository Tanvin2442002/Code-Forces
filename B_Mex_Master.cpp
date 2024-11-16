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
    // vector<bool> a(n + 1, false);
    vector<int> b(n);
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] == 0)
        cnt++;
      if (b[i] == 1)
        cnt1++;
    }
    int x = ceil(n / 2.0);
    if (cnt == n)
      cout << 1 << endl;
    else {
      if (cnt <= x)
        cout << 0 << endl;
      else if (cnt > x) {
        if ((cnt1 > 0 and cnt + cnt1 < n) or cnt1==0)
          cout << 1 << endl;
        else
          cout << 2 << endl;
      }
    }
  }
  return 0;
}