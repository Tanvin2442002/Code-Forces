#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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
int inf  = 2e18;

int check(int x,int p){
  int ans = 1, pw = 1;
  for(int i = 0;i<p;i++){
    if(inf/pw<x)return inf;
    pw*=x;
    ans+=pw;
    if(ans>inf)return inf;
  }
  return ans;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      bool f = 0;
      for(int i=2;i<=70;i++){
        int lo = 2 ,hi=1e18;
        while(lo<=hi){
          int mid = (lo+hi)/ 2;
          int val = check(mid,i);
          if(val==n){
            f = 1;
            break;
          }
          if(val<n)lo = mid + 1;
          else hi = mid - 1;
        }
      }
      if(f)cout <<"YES" <<endl;
      else cout <<"NO" <<endl;
    }
  return 0;
}

// n^m - 1/n-1
//