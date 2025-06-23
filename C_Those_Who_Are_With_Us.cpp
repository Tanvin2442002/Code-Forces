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
      int n,m;
      cin >> n >> m;
      vector<vector<int>>v(n,vector<int>(m));
      int mx = 0;
      for(int i = 0;i<n; i++){
        for(int j=0;j<m;j++){
          cin >> v[i][j];
          mx = max(mx,v[i][j]);
        }
      }

      vector<int>mxcols(m,0);
      vector<vector<int>>rows(n);
      int cntmx = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(v[i][j]==mx){
            mxcols[j]++;
            rows[i].push_back(j);
            cntmx++;
          }
        }
      }

      int cntcolsmx = 0;
      for(auto i:mxcols){
        if(i>0)cntcolsmx++;
      }
      vector<int>r_rows(n,0);
      for(int i=0;i<n;i++){
        int cntt = 0;
        for(int j:rows[i]){
          if(mxcols[j]==1)cntt++;
        }
        r_rows[i]=cntt;
      }

    //  dbg(r_rows);

      bool f=false;
      for(int i=0;i<n;i++){
        if(rows[i].empty())continue;
        if(cntcolsmx-r_rows[i] <=1 ){
          f = true;
          break;
        }
      }

      if(f)cout << mx-1 << endl;
      else cout << mx << endl;

    }
    return 0;
}