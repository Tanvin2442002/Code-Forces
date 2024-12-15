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
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 >= l2 and l1 <= r2)
      cout << l1 << "\n";
    else if (l2 >= l1 and l2 <= r1)
      cout << l2 << "\n";
    else
      cout << l1 + l2 << "\n";
  }
  return 0;
}