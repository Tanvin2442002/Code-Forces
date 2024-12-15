#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
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
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      bool flag = true;
      int i = 0;
      while(v[i+1]<=v[i] and i<n-1)i++;
      if(i==n-1){
        cout<<"YES"<<endl;
        continue;
      }
      i = 0;
      while(v[i+1]>=v[i] and i<n-1)i++;
      // dbg(i);
      if(i==n-1)flag = true;
      else {
        while(v[i+1]<=v[i] and i<n-1)i++;
        if(i==n-1)flag=true;
        else flag = false;
      }
      if(flag)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    return 0;
}