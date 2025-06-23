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
      int n,k;
      cin >> n >> k;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      if(n==k){
        vector<int>tmp;
        for(int i=1;i<n;i+=2){
          tmp.push_back(v[i]);
        }
        tmp.push_back(0);
        int ans=0;
        for(int i=0;i<tmp.size();i++){
          if(tmp[i]!=i+1){
            ans = i+1;
            break;
          }
        }
        cout << ans << endl;
        continue;
      }
      else {
        int idx = 0;
        for(int i=1;i<n;i++){
          if(v[i]!=1){
            idx = i;
            break;
          }
        }
        if(idx==0){
          cout << 2 << endl;
          continue;
        }
        int seg = k - (n - idx - 1); 
        if(seg>2)cout << 2 << endl;
        else cout << 1 << endl;
        // dbg(seg,idx-seg);
      }
    } 
    return 0;
}