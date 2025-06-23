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
    cin >> t;
    while(t--){
      int n,m;
      cin >> n >> m;
      vector<vector<ll>>v(n,vector<ll>(m+1));
      for(int i=0;i<n;i++){
        for(int j=1;j<m+1;j++){
          cin >> v[i][j];
        }
        v[i][0] = accumulate(vf(v[i]),0LL);
      }
      //dbg(v);
      sort(vr(v));
      vector<ll>a;
      for(int i=0;i<n;i++){
        for(int j=1;j<m+1;j++){
           a.push_back(v[i][j]);
        }
      }
      vector<ll>presum(a.size());
      //dbg(a);
      presum[0]=a[0];
      for(int i=1;i<presum.size();i++){
        presum[i]=presum[i-1]+a[i];
      }
      //dbg(presum);
      cout << accumulate(vf(presum),0LL)<< endl;
    }
    return 0;
}