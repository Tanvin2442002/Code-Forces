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
      int x,y;
      cin >> x >> y;
      if(x%9==0 and y==1){
        cout<<"YES"<<endl;
        continue;
      }
      int diff = (x-y);
      if(abs(diff)==1 or (diff+1>0 and (diff+1)%9==0)){
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    return 0;
}