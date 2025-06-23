#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_set_g = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_multiset_g = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
int inf  = 1e18;



int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n,q;
      cin >> n >> q;
      o_set<pair<int,int>>s;
      vector<int>v(n+1);
      for(int i=1;i<=n;i++){
        cin >> v[i];
        s.insert({v[i],i});
      }
      while(q--){
        char x;
        cin >> x;
        if(x=='?'){
          int a,b;
          cin >> a >> b;
          cout << s.order_of_key({b+1,0}) - s.order_of_key({a,0}) << endl;;
        }
        else{
          int k,a;
          cin >> k >> a;
          s.erase({v[k],k});
          s.insert({a,k});
          v[k]=a;
        }
      }
    }
    return 0;
}