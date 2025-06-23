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

int mod = 1000000007;
ll inf = 1e18;

int MaxValue(vector<int>& a, int ind, int n) {
    int leftSeg = ind, rightSeg = n - ind - 1;
    if (leftSeg == 1 && rightSeg == 1) {
        int x = abs(abs(a[ind] - a[ind - 1]) - a[ind + 1]);
        int y = abs(abs(a[ind] - a[ind + 1]) - a[ind - 1]);
        return max({a[ind - 1], x, y, a[ind + 1]});
    }
    else if (leftSeg == 1) {
        return abs(a[ind] - a[ind - 1]);
    }
    else if (rightSeg == 1) {
        return abs(a[ind] - a[ind + 1]);
    }
    else {
        return a[ind];
    }
}
int32_t main() {
    fastio; in; out;
    int t = 1;
    cin >> t;
    while (t--) {
      int n;
      cin >> n;
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
          cin >> v[i];
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
          ans = max(ans, MaxValue(v, i, n));
      }
      cout << ans << '\n';
    }
    return 0;
}
