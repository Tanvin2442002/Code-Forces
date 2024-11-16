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

int32_t main() {
  fastio;
  in;
  out;

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        v[i][j] = s[j] - '0';
      }
    }
    int ans = 0;
    int x = min(n, m) / 2;
    for (int i = 0; i < x; i++) {
      vector<int> a;
      int top = i;
      int bottom = n - 1 - i;
      int left = i;
      int right = m - 1 - i;

      if (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
          a.push_back(v[top][j]);
        }

        for (int i = top + 1; i <= bottom; i++) {
          a.push_back(v[i][right]);
        }

        for (int j = right - 1; j >= left; j--) {
          a.push_back(v[bottom][j]);
        }

        for (int i = bottom - 1; i > top; i--) {
          a.push_back(v[i][left]);
        }
        int sz = a.size();
        vector<int> b = a;
        b.insert(b.end(), a.begin(), a.end());
        for (int i = 0; i < sz; i++) {
          if (i + 3 < b.size() and
              b[i] == 1 and
              b[i + 1] == 5 and
              b[i + 2] == 4 and
              b[i + 3] == 3) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
