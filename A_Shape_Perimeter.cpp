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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n,m;
      cin >> n >> m;
      int s1 = 0;
      int s2 = 0;
      vector<pair<int,int>>p(n);
      for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
      }
      for(int i=1;i<n;i++){
        s2+=p[i].second;
        s1+=p[i].first;
      }
      s2*=2;
      s1*=2;
      cout << s2+s1+(4*m)<<endl;
    }
    return 0;
}