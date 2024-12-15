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
      vector<int>v(n);
      map<int,int>mp;
      for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
      }
      int x = n-2;
      int ans1=0,ans2=0;
      vector<pair<int,int>>div;
      for(int i=0;i<n;i++){
        if(x%v[i]==0){
           int a = v[i];
           int b = x/v[i];
           if(a==b){
              if(mp[a]>1){
                ans1=a;
                ans2=b;
              }
           }
           else if(mp[a]>0 and mp[b]>0){
             ans1 = a;
             ans2 = b;
             break;
           }
        }
      }
      cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}