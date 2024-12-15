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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n,k;
      cin >> n >>k;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      vector<int>res;
      int c = 0;
      for(int i = 0;i<500000 ;i++){
        bool flag = true;
        for(int i=0;i<n-1;i++){
          if(v[i]>v[i+1]){
            flag = false ;
            int a = v[i+1] + k;
            v[i+1] = v[i];
            v[i] = a;
            res.push_back(i+1);
            break;
          }
        }
        // dbg(v);
        if(flag){
          cout <<"Yes"<<endl;
          cout<<res.size()<<endl;
          for(auto i : res){
            cout << i <<" ";
          }
          c = 1;
          cout<<endl;
          break;
        }
      }
      if(!c)cout<<"No"<<endl;
    }
    return 0;
}


// 5 50
// 2 1 3 4 5
// 51 2 3 4 5
// 52 51 3 4 5
// 101 52 3 4 5
// 102 101 