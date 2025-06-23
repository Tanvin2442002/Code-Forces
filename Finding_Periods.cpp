#pragma GCC optimize("O3")
#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else 
// #define dbg(x...)
// #define dbgc(x...)
// #endif
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

vector<int>prefix_function(string s){
  int n = s.size();
  vector<int>pi(n);
  int i = 1, j = 0;
  while(i<n){
    if(s[i]==s[j]){
      j++;
      pi[i]=j;
      i++;
    }
    else {
      if(j==0){
        pi[i]=0;
        i++;
      }
      else j = pi[j-1];
    }
  }
  return pi;
}


int32_t main()
{
    fastio;in;out;
    int t = 1;
    // cin >> t;
    while(t--){
       string s;
       cin >> s;
       vector<int>lps = prefix_function(s);
      // cerr << mx << endl;
      vector<int>p;
      int l = s.size();
      // p.push_back(l);
      int n = s.size();
      while(l>0){
         l = lps[l-1];
         int a = n - l;
         p.push_back(a);
      }
      sort(vf(p));
      for(auto i:p){
        cout << i << " ";
      }
      cout << endl;
    }
    return 0;
}