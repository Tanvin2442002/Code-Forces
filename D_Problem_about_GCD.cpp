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
    cin >> t;
    while(t--){
      int l,r,g;
      cin >> l >> r >> g;
      int a = ((l+g-1)/g)*g;
      int b = (r/g)*g;
      // b *= g;
      if(b%a==0 and a!=g){
        b-=g;
      }
      if(a==b and a==g)cout << a << " " << b <<endl;
      else if(a==b and a!=g)cout << -1 << " " << -1 <<endl;
      else if(a<b)cout << a <<" " << b<<endl;
      else cout << -1 << " " << -1 <<endl;
    }
    return 0;
}


