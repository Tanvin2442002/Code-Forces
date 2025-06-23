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
      vector<vector<int>>v(n,vector<int>(m));
      map<int,vector<pair<int,int>>>mp;
      for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
          cin >> v[i][j];
          mp[v[i][j]].push_back({i,j});
        }
      }
      vector<int>mv;
      for(auto i:mp){
        set<pair<int,int>>st;
        bool f = false;
        while(!i.second.empty()){
          pair<int,int> x = i.second.back();
          i.second.pop_back();
          int a = x.first;
          int b = x.second;
          if(st.find({a+1,b})==st.end() and st.find({a-1,b})==st.end() and st.find({a,b+1})==st.end() and st.find({a,b-1})==st.end()){
              st.insert({a,b});
          }
          else {
              mv.push_back(2);
              f = true;
              break;          
          }
        }
        if(!f)mv.push_back(1);
      }
      cout << accumulate(vf(mv),0LL) - *max_element(vf(mv)) << endl;
    }
    return 0;
}