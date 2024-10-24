#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifdef ONPC
#include "mydebug.h"
#else
#define debug(...) 1
#endif

const int mod = 1e9 + 7;

int power(int base, int n, int m = mod) {
  if (n == 0)
    return 1;
  if (n & 1) {
    int x = power(base, n / 2);
    return ((x * x) % m * base) % m;
  } else {
    int x = power(base, n / 2);
    return (x * x) % m;
  }
}

const int N = 1000005;
int fact[N];

int inverseMod(int a, int m) { return power(a, m - 2); }

int nCr(int n, int r, int m = mod) {
  if (r == 0)
    return 1;
  if (r > n)
    return 0;
  return (fact[n] * inverseMod((fact[r] * fact[n - r]) % m, m)) % m;
}

int catalan(int n) {
  int x = nCr(2 * n, n);
  int y = nCr(2 * n, n - 1);
  int ans = (x - y + mod) % mod;
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  debug(n, k);
  int res = (catalan(n) * power(k, n)) % mod;
  cout << res << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
  int n = 1;
  //	cin >> n;
  for (int i = 1; i <= n; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}
