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

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(vf(v));
    int s = 0;
    for (int i : v) {
      s = (s + i) % mod;
    }
    for (int i = 0; i < n; i++) {
      m[s - v[i]]++;
    }
    int c = 0;
    c = (s - v[n - 1] + mod) % mod;
    while (m[c] % x == 0) {
      m[c + 1] += (m[c] / x);
      m[c] %= x;
      c++;
      c %= mod;
    }
    
    cout << power(x, c) << endl;
  }
  return 0;
}