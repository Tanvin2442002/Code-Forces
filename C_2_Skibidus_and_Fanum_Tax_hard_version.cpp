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
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      vector<int>b(m);
      for(int i=0;i<m;i++){
        cin >> b[i];
      }
      sort(vf(b));
      if(b[0]-v[0]<v[0]){
        v[0]=b[0]-v[0];
      }
      int lo = v[0];
      for(int i=1;i<n-1;i++){
        int hi = 1e18;
        if(v[i]>=lo){
            hi = v[i];
        }
        int needed = lo+v[i];
        int idx = lower_bound(vf(b),needed)-b.begin();
        if(idx<m){
           int val = b[idx]-v[i];
           v[i]=min(hi,val);
        }
        lo = v[i];
      }
      for(auto i:v){
        cout << i << " ";
      }
      cout << endl;
      if(is_sorted(vf(v)))cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    return 0;
}


