#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    // cin >> t;
    while(t--){
      int n,m;
      cin >> n >> m;
      float ans = 0;
      for(int i=1;i<=n;i++){
        float x = ((float)i/n);
        float y = pow(x,m);
        float xx = ((float)(i-1)/n);
        float yy = pow(xx,m);
        ans+=i*(y-yy);
      }
      cout << fixed << setprecision(10) << ans <<endl;
    }
    return 0;
}