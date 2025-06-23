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
    int n;
    cin >> n;
    vector<int> v(n);
    int c = 1;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int val = v[0];
    for (int i = 1; i < n; i++) {
      if (v[i] - val > 1) {
        c++;
        val = v[i];
      }
    }
    cout << c << endl;
  }
  return 0;
}