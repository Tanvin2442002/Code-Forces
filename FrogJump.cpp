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

int jump(int n,vector<int>&stairs,vector<int>&dp){
  if(n == 0) return 0;
  if(dp[n]!=-1)return dp[n];
  int left = jump(n-1,stairs,dp)+abs(stairs[n]-stairs[n-1]);
  int right = INT_MAX;
  if(n>1){
     right = jump(n-2,stairs,dp)+abs(stairs[n]-stairs[n-2]);
  }
  return dp[n] = min(left,right);
}

int frogJump(int n,vector<int>&heights){
    vector<int>dp(n,-1);
    return jump(n-1,heights,dp);
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int>stairs(n,0);
      for(int i=0;i<n;i++){
        cin >> stairs[i];
      }
      cout << frogJump(n,stairs)<<endl;      
    }
    return 0;
}




