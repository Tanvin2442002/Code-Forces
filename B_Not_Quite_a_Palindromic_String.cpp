#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
ll inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    int m = n / 2;
    int d = m - k;

    if (d < 0) {
      cout << "NO\n";
      continue;
    }
    if (zero >= d and one >= d and ((zero - d) % 2 == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}