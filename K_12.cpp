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
int inf  = 1e18;

int f(vector<int>&v,vector<int>&cost,int mid){
  int sum = 0;
  for(int i=0;i<v.size();i++){
    sum+=(abs(mid-v[i])*cost[i]);
  }
  return sum;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int>v(n);
      vector<int>cost(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      for(int i = 0; i<n ; i++){
        cin >> cost[i];
      }
      int lo = *min_element(vf(v));
      int hi = *max_element(vf(v));
      while(lo<=hi){
        int mid1 = lo + (hi -lo)/3;
        int mid2 = hi - (hi -lo)/3;
        int f1 = f(v,cost,mid1);
        int f2 = f(v,cost,mid2);
        if(f1>f2){
          lo = mid1 + 1;
        }
        else hi = mid2 - 1;
      }
      cout<<f(v,cost,lo)<<endl;
    }
    return 0;
}