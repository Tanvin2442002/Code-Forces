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
    // cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int>grundy(n+1);
      vector<int>firstmissinggrundy[n+1];
      vector<int>lastappearance(n+1);
      grundy[0]=grundy[1]=grundy[2]=0;
      int mn = INT_MAX;
      for(int i=1;i<=n;i++){
        for(auto it:firstmissinggrundy[i]){
           lastappearance[it]=i;
        }
        while(lastappearance[grundy[i]]==i)grundy[i]++;
        int s=0,v=0;
        for(int j=i; j>=0 and s+j<=n; j--){
          s+=j;
          v^=grundy[j];
          if(j<i)firstmissinggrundy[s].push_back(v);
          if(s==n and j<i and v==0) mn = min(mn,i-j+1); 
        }
      }
      dbg(grundy);
      if(!grundy[n]) cout << -1 << endl;
      else cout <<mn << endl;
    }
    return 0;
}