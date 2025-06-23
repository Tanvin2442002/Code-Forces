#pragma GCC optimize("O3")
#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else 
// #define dbg(x...)
// #define dbgc(x...)
// #endif
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

// ld gamma = 0.5772156649;


void solve(){
  int n;
  cin >> n;
  // ld ln_n = log(n);
  ll j = 0;
  ll ans = 0;
  for(ll i=1;i<=n;i=j+1){
     ll divisor = n/i;
     ll nth_div = n/divisor;
     j = nth_div;
     ans+= (divisor*(nth_div-i+1));
    //  dbg(divisor,nth_div,ans);
  }
  cout << ans << "\n";
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}