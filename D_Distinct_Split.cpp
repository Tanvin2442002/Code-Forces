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
      int n;
      cin>>n;
      string s;
      cin >> s;
      set<int>l,r;
      vector<int>ll(n),rr(n);
      for(int i=0;i<n;i++){
        l.insert(s[i]);
        ll[i]=l.size();
      }
      for(int i=n-1;i>=0;i--){
        r.insert(s[i]);
        rr[i]=r.size();
      }
      int ans = 0;
      for(int i=0;i<n-1;i++){
        ans = max(ans,ll[i]+rr[i+1]);
      }
      cout<<ans<<endl;
    }
    return 0;
}