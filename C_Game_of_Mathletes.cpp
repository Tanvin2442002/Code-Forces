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
      sort(vf(v));
     // dbg(v);
      int i=0,j=n-1;
      int cnt = 0;
      while(i<j){
        int s = v[i]+v[j];
       // dbg(s,cnt,i,j);
        if(s>k)j--;
        else if(s<k){
          i++;
        }
        else if(s==k)  {
          cnt++;
          i++;
          j--;
        }
      }
      cout << cnt <<endl;
    }
    return 0;
}