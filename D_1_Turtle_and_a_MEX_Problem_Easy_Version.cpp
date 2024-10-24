#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
//  #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    while (n--) {
      int x;
      cin >> x;
      vector<bool>length(x+2,false);
      for(int i=0;i<x;i++){
        int y;
        cin>>y;
        if(y<=x){
          length[y]=true;
        }
      }
      int miss = 0;
      for(int i=0;i<length.size();i++){
        if(!length[i]){
          miss++;
        }
        if(miss==2){
            v.push_back(i);
            break;
        }
      }
    }
    dbg(v);
    int ans = *max_element(vf(v));
    int steps = 0;
    int sum1 = m*(m+1)/2;
    int stop = min(m,ans);
    steps = (stop+1)*ans;
    if(m>ans){
        steps+=sum1 - (ans*(ans+1)/2); 
    }
    cout << steps << endl;
  }
  return 0;
}