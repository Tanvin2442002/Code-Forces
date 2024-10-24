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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(vr(a));
    int ans = 0;
    int steps = 0;
    while (ans < k) {
      int x = a.back();
      cerr<<"x: "<<x<<endl;
      // cerr<<x<<endl;
      for (int i = 0; i < a.size(); i++) {
        ans+=x;
        a[i]-=x;
        steps++;
        if(ans>=k)break;
      }
      cerr<<"ans: "<<ans<<endl;
      while(a.back()==x){
        a.pop_back();
        steps++;
      }
    }
    cout << steps << endl;
  }
  return 0;
}