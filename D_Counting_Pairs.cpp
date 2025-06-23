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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n,x,y;
      cin >> n >> x >> y;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      sort(vf(v));
      int sum = accumulate(vf(v),0LL);
      int l = sum - y;
      int r = sum - x;
      int cnt = 0;
      for(int i = 0;i<n-1;i++){
        int choto = l - v[i];
        int boro = r - v[i];
        int left = lower_bound(v.begin()+i+1,v.end(),choto)-v.begin();
        int right = upper_bound(v.begin()+i+1,v.end(),boro)-v.begin();
        cnt += (right - left);
      } 
      cout << cnt << endl;
    }
    return 0;
}