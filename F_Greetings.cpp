#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

bool compare(pair<int,int>&a,pair<int,int>&b){
  if(a.first<=b.first)return true;
  return false;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<pair<int,int>>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
      } 
      sort(vf(v),compare);
      o_set<int>os;
      os.insert(v[0].second);
      int ans = 0;
      for(int i=1;i<n;i++){
        ans+=(os.size()-os.order_of_key(v[i].second));
        os.insert(v[i].second);
      }
      cout << ans << endl;
    }
    return 0;
}