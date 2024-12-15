#pragma GCC optimize("O3")
#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else
// #define dbg(x...)
// #define dbgc(x...)
// #endif
using namespace std;

#define int long long
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
      int k,l1,r1,l2,r2;
      cin >> k >> l1 >> r1 >> l2 >> r2;
      // vector<int>v;
      int val = 1;
      // int j = 0;
      int cnt = 0;
      while(val <= 1e9){
         int l = l1*val;
         int r = r1*val;
         l = max(l2,l),r = min(r2,r);
         cnt+=max(0LL,r/val-(l-1)/val);
         val*=k; 
      }
      cout << cnt << endl;
    }
    return 0;
}
