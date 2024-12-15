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

bool prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

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
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int gcd = 0;
    for (int i = 0; i < n; i++) {
      gcd = __gcd(v[i], gcd);
    }
    if (gcd == 1)
      cout << 0 << endl;
    else {
      int ans = 0;
      int res = INT_MAX;
      if(__gcd(n,gcd)==1)cout<<1<<endl;
      else if(__gcd(n-1,gcd)==1)cout<<2<<endl;
      else cout << 3 << endl;
    }
  }
  return 0;
}


