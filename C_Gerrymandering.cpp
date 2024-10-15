#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif

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
    string s[2];
    cin >> s[0] >> s[1];
    int a[2][n];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = s[i][j] == 'A' ? 1 : 0;
      }
    }
    int ans = 0;
    vector<array<int, 3>> dp(n + 5, {0, 0, 0});
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 3; j++) {
        if (j == 0) {
          if (i + 2 < n) {
            int c = a[0][i] + a[0][i + 1] + a[0][i + 2] >= 2 ? 1 : 0;
            c += a[1][i] + a[1][i + 1] + a[1][i + 2] >= 2 ? 1 : 0;
            dp[i][0] = max(dp[i][0], c + dp[i + 3][0]);
          }
          if (i + 1 < n) {
            int c = a[0][i] + a[0][i + 1] + a[1][i] >= 2 ? 1 : 0;
            dp[i][0] = max(dp[i][0], c + dp[i + 1][1]);
          }
          if (i + 1 < n) {
            int c = a[1][i] + a[1][i + 1] + a[0][i] >= 2 ? 1 : 0;
            dp[i][0] = max(dp[i][0], c + dp[i + 1][2]);
          }
        } else if (j == 1) {
          if (i + 3 < n) {
            int c = a[0][i + 1] + a[0][i + 2] + a[0][i + 3] >= 2 ? 1 : 0;
            c += a[1][i] + a[1][i + 1] + a[1][i + 2] >= 2 ? 1 : 0;
            dp[i][1] = max(dp[i][1], c + dp[i + 3][1]);
          }
          if (i + 1 < n) {
            int c = a[0][i + 1] + a[1][i] + a[1][i + 1] >= 2 ? 1 : 0;
            dp[i][1] = max(dp[i][1], c + dp[i + 2][0]);
          }
        } else if (j == 2) {
          if (i + 3 < n) {
            int c = a[1][i + 1] + a[1][i + 2] + a[1][i + 3] >= 2 ? 1 : 0;
            c += a[0][i] + a[0][i + 1] + a[0][i + 2] >= 2 ? 1 : 0;
            dp[i][2] = max(dp[i][2], c + dp[i + 3][2]);
          }
          if (i + 1 < n) {
            int c = a[1][i + 1] + a[0][i] + a[0][i + 1] >= 2 ? 1 : 0;
            dp[i][2] = max(dp[i][2], c + dp[i + 2][0]);
          }
        }
      }
    }
    ans = dp[0][0];
    cout << ans << endl;
  }
  return 0;
}