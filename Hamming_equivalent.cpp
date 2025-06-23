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

int mod  = 1000000007;
ll inf  = 1e18;

int32_t main()
{
    fastio; in; out;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, set<int>> mp;
        vector<int> v(n);
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++) {
            int pop_count = __builtin_popcount(v[i]);
            mp[pop_count].insert(i+1);
        }

        bool is_valid = true;
        for(int i=0;i<n;i++){
          int x = __builtin_popcount(v[i]);
          set<int>&st = mp[x];
          if(st.find(v[i])==st.end()){
            is_valid = false;
            break; 
          }
        }
        if (is_valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
