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
      int n , q;
      cin >> n >>q;
      map<int,int>mp;
      for(int i = 0;i<n;i++){
        int x ;
        cin >> x;
        mp[i+1]=x;
      }
      vector<int>v(q);
      int cnt = 0;
      for(int i = 0;i<q;i++){
        int x;
        cin >> x;
        mp[x]--;
        if(mp[x]<0){
          cnt++;
        }
      }
      cout<<cnt<<endl;
    }
    return 0;
}