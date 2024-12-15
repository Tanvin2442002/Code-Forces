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
    int n, b, c;
    cin >> n >> b >> c;
    if (c >= n and b != 0) {
      cout << n << endl;
      continue;
    }
    // cout << n<<b<<c;
    if (b == 0) {
      if(c>=n){
        cout<<n<<endl;
      }
      else if (c < n - 2)
        cout << -1 << endl;
      else
        cout << n - 1 << endl;
    } else
      cout << n - max(0LL, 1 + (n - c - 1) / b) << endl;
  }
  return 0;
}