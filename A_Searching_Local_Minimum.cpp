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

int query(int mid) {
  cout << "? " << mid << endl;
  cout.flush();
  int val;
  cin >> val;
  return val;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int x, y, z;
      if (mid - 1 == 0)
        x = inf;
      else {
        x = query(mid - 1);
      }
      y = query(mid);
      if (mid + 1 == n + 1)

        z = inf;
      else {
        z = query(mid + 1);
      }
      if (y < min(x, z)) {
        cout << "! " << mid << endl;
        break;
      }
      if (x < y)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
  }
  return 0;
}