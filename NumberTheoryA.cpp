#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
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
    // cin >> t;
    while(t--){
      ll n;
      cin >> n;
      ll i = 1;
      vector<ll>v;
      while(i<=n){
          ll ans = n/i;
          v.push_back(ans);
          ll next = n/ans + 1;
          i = next;
      }
      sort(vf(v));
      cout << v.size() << "\n";
      for(auto i:v){
        cout << i <<" ";
      }
      cout << "\n";
    }
    return 0;
}