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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    if(n==1){
      cout<<1<<"\n";
      continue;
    }
    if (n % 2 == 0) {
      int cnt = 0;
      for (int i = 1; i < n; i += 2) {
        cnt = max(cnt, v[i] - v[i - 1]);
      }
      cout << cnt << endl;
    } else {
      int ans = infi;
      for (int i = 0; i < n; i++) {
        vector<int> a;
        for (int j = 0; j < n; j++) {
          if (j != i) {
            a.push_back(v[j]);
          }
        }
        int cnt = 0;
        for (int l = 1; l < n; l += 2) {
          cnt = max(cnt, a[l] - a[l - 1]);
        }
        ans = min(ans, cnt);
      }
      cout << ans << endl;
    }
  }
  return 0;
}