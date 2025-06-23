#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define float long double
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
    cin >> t;
    while(t--){
      int a,b,d,e;
      cin >> a >> b >> d >> e;
      int mx = 0;
      for(int i=-500;i<500;i++){
         int c = 0;
         if(a+b==i)c++;
         if(b+i==d)c++;
         if(i+d==e)c++;
         mx = max(mx,c);
      }
      cout << mx << endl;
    }
    return 0;
}