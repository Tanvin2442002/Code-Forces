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
    int x, m;
    cin >> x >> m;
    int b = log2(x);
    int lo = 1 << b;
    int hi = 1 << (b + 1);
    int cnt = 0;

    for (int i = lo; i <= hi and i <= m; i++) {
      if (x == i)
        continue;
      if (x % (x ^ i) == 0 or i % (x ^ i) == 0)
        cnt++;
    }

    cout << cnt << endl;
  }
  return 0;
}