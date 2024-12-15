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
      int n,k;
      cin >> n >>k;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      bool f = false;
      int cnt = 0;
      int val = 0;
      if(n==1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        continue;
      }
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(abs(v[i]-v[j])%k!=0 and i!=j){
            cnt++;
            if(cnt==n-1){
              f = true;
              val = i+1;
              break;
            }
          }
        }
        if(f)break;
        else {
          cnt = 0;
        }
      }
      if(f){
        cout<<"YES"<<endl;
        cout<<val<<endl;
      }
      else cout <<"NO"<<endl;
    }
    return 0;
}