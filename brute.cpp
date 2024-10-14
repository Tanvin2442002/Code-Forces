#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "mydebug.h"
#else
#define debug(...) 1
#endif

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.rbegin(), a.rend());
  for (int i = 1; i < n; i += 2) {
    if (k == 0) break;
    if (a[i - 1] - a[i] <= k) {
      int kk = k;
      k -= a[i-1] - a[i];
      a[i] += kk - k;
    }
    else {
      a[i] += k;
      k = 0;
    }
  }
  debug(a);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) x += a[i];
    else y += a[i];
  }
  cout << x - y << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    // cout<<"Case "<<i<<": ";
    solve();
  }
}
