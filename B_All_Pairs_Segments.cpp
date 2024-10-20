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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int prev = 0;
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
      prefix[i] = prev + (n - i );
      prev = prefix[i] - i + 1;
    }
    map<int, int> mp;
    for(int i=1;i<=n;i++) {
      mp[prefix[i]] += 1;
      if(i + 1 <= n) mp[i*(n - i)] += a[i + 1] - a[i] - 1;
    }
    // for(auto x: prefix) cout<<x<<" ";
    while(k--) {
      int x;
      cin >> x;
      cout<<mp[x]<<" ";
    }
    cout<<endl;
  }
  return 0;
}