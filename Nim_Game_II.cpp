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

int mex(vector<int> &a) {
  vector<bool> f(a.size() + 1, 0);
  for (int i : a)
    if (i <= (int)a.size())
      f[i] = 1;
  int mex = 0;
  while (f[mex]) ++mex;
  return mex;
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
      //vector<int>grundy(n+3);
      for(int i=0;i<n;i++){
        cin >> v[i];
        v[i]%=4;
      }
      // int mx = *max_element(vf(v));
      int xr = 0;
      for(int i=0;i<n;i++){
        xr ^= v[i];
      }
      if(xr)cout <<"first" << endl;
      else cout << "second" << endl;
    }
    return 0;
}