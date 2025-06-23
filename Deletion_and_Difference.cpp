#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      map<int,int>mp;
      for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
      }
      int sz = 0;
      int left = 0;
      for(auto i:mp){
         if(i.first==0)sz+=i.second;
         else {
            sz+=(i.second/2);
            if(i.second%2!=0)left+=1;
         }
      }
      if(sz>0) left++;
      cout << left << '\n';
    }
    return 0;
}