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
      int n;
      cin >> n;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      bool f = false;
      for(int i=0;i<n;i++){
        int l = i;
        int r = n-(i+1);
        if(v[i]<=2*max(l,r)){
          f = true;
          break;
        }
      }
      if(f)cout << "NO" << endl;
      else cout << "YES" <<endl;
    }
    return 0;
}