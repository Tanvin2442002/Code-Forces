#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;


void solve(){
  ll n;
  cin >> n;
  ll ans = 0;
  ll next =0;
  for(ll i=1;i<=n;i=next+1){
    ll div = n/i;
    next = n/div;
    ll cnt = next-i+1;
    ll res = 0;
    if(cnt%2){
      ll tmp = next+i;
      tmp/=2;
      res = (cnt%mod)*(tmp%mod)%mod;
    }
    else {
      cnt/=2;
      res = (cnt % mod) * ((next + i) % mod) % mod;
    }
    ans = (ans + (res*div)%mod)%mod;
  }
  cout << ans << "\n";
}


int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}