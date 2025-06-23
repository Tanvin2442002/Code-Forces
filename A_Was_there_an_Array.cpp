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
      int n;
      cin >> n;
      int sz = n - 2;
      vector<int>v(n-2);
      for(int i=0;i<sz;i++){
        cin >> v[i];
      }
      if(sz<3){
        cout << "YES" << endl;
        continue;
      }
      bool f = false;
      for(int i=0;i<sz-2;i++){
        if(v[i]==1 and v[i+1]==0 and v[i+2]==1){
          f = true;
          break;
        }
      }
      if(f)cout << "NO" << endl;
      else cout << "YES" << endl;
    }
    return 0;
}