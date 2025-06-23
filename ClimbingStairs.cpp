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

ll countstairs(int n,vector<ll>&dp){
  if(n<0)return 0;
  if(n==0)return 1;
  if(n==1)return 1;
  if(dp[n]!=-1)return dp[n];
  ll left = countstairs(n-1,dp);
  ll right = countstairs(n-2,dp);
  return dp[n] = left + right;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<ll>dp(n+1,-1);
      cout<<countstairs(n,dp)<<endl;
    }
    return 0;
}