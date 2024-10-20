#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
      cin >> points[i].first;
      cin >> points[i].second;
    }
    while (k--) {
      int x, y;
      // unordered_map<int, vector<int>> ans;
      // vector<int>ans;
      cin >> x >> y;
      int l=0,r=0;
      bool flag = false;
      int mx = LLONG_MAX;
      for (int i = 0; i < n; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int dist = ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        // ans[dist].push_back(i + 1);
        if (dist < mx) {
          l = i + 1, r = 0 , flag = false;
          mx = dist;
        } else if (dist == mx) {
           if(r == 0) r = i + 1;
           else flag = true;
        }
      }
      if(flag)cout<<"POINT"<<endl;
      else if(r == 0) cout<<"REGION"<<" "<<l<<endl;
      else cout<<"LINE"<<" "<<l<<" "<<r<<endl;
     
    }
  }
  return 0;
}