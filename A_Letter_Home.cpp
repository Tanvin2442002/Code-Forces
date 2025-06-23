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
    cin >> t;
    while(t--){
      int n,x;
      cin >> n >> x;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      sort(vf(v));
      int mn = v[0];
      int mx = v[n-1];
      int d = abs(mn-x);
      int d2 = abs(mx-x);
      if(d<d2){
        cout << d + (mx-mn) << endl;
      }
      else cout << d2+(mx-mn) << endl;
    }
    return 0;
}