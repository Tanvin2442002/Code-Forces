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
      cin >> n;
      vector<int> a(n+1);
      vector<int>b(n);
      int x;
      for(int i=0;i<=n;i++){
        cin >> a[i];
        if(i==n)x=a[i];
        if(i<n)b[i]=a[i];
      }
      sort(vf(b));
      for(int i=0;i<n;i++){
        if(b[i]<=2*x){
          if(x<=b[i]){
            x=b[i];
          }
          // cerr<<x<<" ";
        }
      }
      // cerr<<endl;
      cout << accumulate(vf(a),0LL)-x <<"\n";
    }
    return 0;
}