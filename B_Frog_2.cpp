#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;

int jump(int n,vector<int>&stairs,vector<int>&dp,int k){
  if(n == 0) return 0;
  if(dp[n]!=-1)return dp[n];
  int val = INT_MAX;
  for(int i=1;i<=k;i++){
    if(n-i>=0){
      val = min(val,jump(n-i,stairs,dp,k)+abs(stairs[n]-stairs[n-i]));
    }
    else break;
  }
  return dp[n] = val;
}

int frogJump(int n,vector<int>&heights,int k){
    vector<int>dp(n,-1);
    return jump(n-1,heights,dp, k);
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n,k;
      cin >> n >> k;
      vector<int>stairs(n,0);
      for(int i=0;i<n;i++){
        cin >> stairs[i];
      }
      cout << frogJump(n,stairs,k)<<endl;      
    }
    return 0;
}




