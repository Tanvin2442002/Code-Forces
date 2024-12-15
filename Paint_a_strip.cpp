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
      int n;
      cin >> n;
      if(n==1){
        cout<<1<<endl;
        continue;
      }
      else if(n>1 and n<=4){
        cout<<2<<endl;
        continue;
      }
      else{
        int c = 4;
        int cnt = 2;
        while(c<n){
          c=(2*c+2);
          cnt++;
        }
        cout<<cnt<<endl;
      }
    }
    return 0;
}