#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll  long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n,k;
      cin >> n >> k;
      vector<ll>v(n+1);
      for(int i=1;i<=n;i++){
        cin >> v[i];
      }
      int left = n - k + 1;
      if(k<left) left = k;
      int right = n - left + 1;
      
      ll sum = 0;
      for(int i=1;i<left;i++){
        v[i]*=i;
      }
      int j = 1;
      for(int i=n;i>right;i--){
        v[i]*=j;
        j++;
      }
      for(int i=left;i<=right;i++){
        v[i]*=left;
      }
      sum = accumulate(vf(v),0LL);
      //dbg(v,sum);
      ld ans = (ld)sum/(ld)(n-k+1);
      cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}