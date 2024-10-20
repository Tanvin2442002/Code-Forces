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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(vf(a));
    int x = *max_element(vf(a));
    int y = *min_element(vf(a));
    for (int i = 0; i < n; i++) {
      if (i == 0)
        b[i] = x;
      else
        b[i] = y;
      c[i] = x;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += (c[i] - b[i]);
    }
    cout << sum << endl;
  }
  return 0;
}