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
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    int cnt = 0;
    int cnt1 = 0;
    for (int i = 0; i < 2 * n; i++) {
      cin >> v[i];
      if(v[i] == 0){
        cnt1++;
      }
    }
    dbg(v);
    for (int i = 0; i < 2 * n; i++) {
      if (v[i] == 1) {
        cnt++;
      }
    }
    if(cnt % 2 == 0){
        if(cnt1<cnt){
          cout<<0<<" "<<cnt1<<endl; 
        }
        else{
          cout<<0<<" "<<cnt<<endl;
        }
    }
    else{
      if(cnt1<cnt){
        cout<<1<<" "<<cnt1<<endl;
      }
      else{
        cout<<1<<" "<<cnt<<endl;
      }
    }
  }
  return 0;
}