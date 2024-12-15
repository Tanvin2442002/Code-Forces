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
int n, a, r, m;
int f(vector<int>&v, int mid) {
    int additional = 0,required = 0,cost = 0;
    int c = 0;
    for(int i=0;i<n;i++){
      if(v[i]<mid){
        required+=(mid-v[i]);
        c+=((mid-v[i])*a);
      }
      else {
        additional+=(v[i]-mid);
        c+=((v[i]-mid)*r);
      }
    }
    if (additional == required) cost = additional * m;
    else if(additional>required) cost = required*m + (additional-required)*r;
    else cost = additional*m + (required-additional)*a;
    return min(c,cost);
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    cin >> n >> a >> r >> m;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int lo = 0;
    int hi = 1e9;
    while (lo <= hi) {
      int mid1 = lo + (hi - lo) / 3;
      int mid2 = hi - (hi - lo) / 3;
      int f1 = f(v, mid1);
      int f2 = f(v, mid2);
      if(f1>f2){
        lo = mid1 + 1;
      }
      else hi = mid2 - 1;
    }
    cout<<f(v,lo)<<endl;
  }
  return 0;
}