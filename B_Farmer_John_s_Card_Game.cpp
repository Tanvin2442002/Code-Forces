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
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          cin >> v[i][j];
        }
      }
      for(int i=0;i<n;i++){
        sort(vf(v[i]));
      }
      vector<pair<int,int>>pattern;
      for(int i=0;i<n;i++){
        pattern.push_back({v[i][0],i});
      }
      sort(vf(pattern));
      vector<int>onlyposition;
      for(int i=0;i<n;i++){
        onlyposition.push_back(pattern[i].second);
      }
      vector<int>final;
      for(int i=0;i<m;i++){
        for(int j=0;j<onlyposition.size();j++){
           int x = onlyposition[j];
           final.push_back(v[x][i]);
        }
      }
      if(prev_permutation(vf(final)))cout << -1 <<endl;
      else {
        for(auto i:onlyposition){
          cout << i+1 << " ";
        }
        cout << endl;
      }
    }
    return 0;
}