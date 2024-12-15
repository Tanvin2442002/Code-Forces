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

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;

  int t = 1;
  // cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> dp(n + 1, LLONG_MAX);
    dp[1] = 2;

    for (int i = 1; i <= n; i++) {
      vector<int> new_dp(n + 1, LLONG_MAX);
      for (int j = 1; j <= n; j++) {
        if (i == 1 && j == 1) {
          new_dp[j] = dp[j];
          continue;
        }
        if (i > 1) {
          new_dp[j] = min(new_dp[j], dp[j] + __gcd(a, i) + __gcd(b, j));
        }
        if (j > 1) {
          new_dp[j] = min(new_dp[j], new_dp[j - 1] + __gcd(a, i) + __gcd(b, j));
        }
      }
      dp = new_dp;
    }

    cout << dp[n] << endl;
  }

  return 0;
}
