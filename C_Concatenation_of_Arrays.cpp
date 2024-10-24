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

bool comp(pair<int, int> a, pair<int, int> b) {
  int x = min(a.first, a.second);
  int y = min(b.first, b.second);
  return x < y;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      cin >> a[i].second;
    }
    sort(vf(a), comp);
    for(auto i: a) {
      cout << i.first << " " << i.second << " ";
    }
    cout << endl;
  }
  return 0;
}