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
      vector<int>v(n);
      vector<bool>mark(n+1,false);
      set<int>st;
      for(int i=0;i<n;i++){
        cin >> v[i];
        st.insert(v[i]);
      }
      if(st.size()==n){
        for(int i=0;i<n;i++){
          cout<<v[i]<<" ";
        }
        cout<<endl;
        continue;
      }
      vector<int>b;
      for(int i=0;i<n;i++){
        if(!mark[v[i]]){
          b.push_back(v[i]);
          mark[v[i]]=true;
        }
      }
      for(int i=1;i<=n;i++){
        if(!mark[i])b.push_back(i);
      }
      for(auto i:b){
        cout<<i<<" ";
      }
      cout<<endl;
    }
    return 0;
}