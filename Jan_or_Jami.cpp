#pragma GCC optimize("O3")
#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else 
// #define dbg(x...)
// #define dbgc(x...)
// #endif
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
      string s;
      cin >> s;
      vector<int>v(3);
      for(int i=0;i<s.size();i++){
         int x = 'Z'-s[i];
         v[i] = x%4;
      }
     // dbg(v);
      int ans = 0;
      for(int i=0;i<v.size();i++){
        ans^=v[i];
      }
      if(ans)cout << "Jan" << endl;
      else cout << "Jami" << endl;
    }
    return 0;
}