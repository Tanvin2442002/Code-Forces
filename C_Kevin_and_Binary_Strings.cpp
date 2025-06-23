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
    string s;
    cin >> s;
    int sz = s.size();
    // int l1 = 1, r1 = sz, l2 = sz, r2 = sz;
    int cnt = 0;
    int id = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        while (i < sz and s[i] == '1') {
          cnt++;
          i++;
        }
        id = i;
        break;
      }
    }
    int c = cnt;
    for(int i=id;i<sz;i++){
      while(i<sz and s[i]=='0'){
        i++;
        cnt--;
      }
      break;
    }
    if(cnt>0){
      int dif = c-cnt;
      id-=dif;
      cout << 1 << " " << sz <<" " << min(sz,id + 1) << " " << sz-dif <<endl;
    }
    else {
       cout << 1 << " " << sz << " " << 1 << " " << sz - id << endl;
    }
  }
  return 0;
}