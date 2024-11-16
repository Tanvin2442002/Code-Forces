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
      map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        cin >>v[i];
        mp[v[i]]=i+1;
      }
      set<int>st;
      for(auto i:mp){
        int d = abs(i.first-i.second);
        st.insert(d);
      }
      bool f = true;
      for(auto i:st){
        if(i>1){
          f=false;
          break;
        }
      }
      if(f)cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    return 0;
}