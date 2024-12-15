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
const int N = 1e6+5;

int Prime[N + 4], kk;
bool notPrime[N + 5];
void SieveOf() {
  notPrime[1] = true;
  Prime[kk++] = 2;
  for (int i = 4; i <= N; i += 2) notPrime[i] = true;
  for (int i = 3; i <= N; i += 2) {
    if (!notPrime[i]) {
      Prime[kk++] = i;
      for (int j = i * i; j <= N; j += 2 * i) notPrime[j] = true;
    }
  }
}



int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    SieveOf();
    while(t--){
      int n;
      cin >> n;
      vector<int>v;
      for(int i=1;i<=n;i+=2){
        v.push_back(i);
      }
      vector<int>even;
      for(int i = 2;i<=n;i+=2){
        even.push_back(i);
      }
      dbg(Prime);
      reverse(vf(even));
      int x = v.back();
      int val = 0;
      bool f = false;
      for(auto i:even){
        int check = x + i;
        if(notPrime[check]){
          val = i;
          f = true;
          break;
        }
      }
      if(f){
        // even.erase(val);
        for(auto i:v){
          cout<<i<<" ";
        }
        cout <<val<<" ";
        for(auto i:even){
          if(i!=val){
            cout<<i<<" ";
          }
        }
      }
      else cout<<-1;
      cout<<endl;
    }
    return 0;
}