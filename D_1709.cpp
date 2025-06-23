#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
ll inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<pair<int, int>> operations;
    bool f = true;
    while (f) {
      f = false;
      for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
          swap(a[i], b[i]);
          operations.push_back({3, i + 1});
          f = true;
        }
      }
      for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          operations.push_back({1, i + 1});
          f = true;
        }
      }

      for (int i = 0; i < n - 1; i++) {
        if (b[i] > b[i + 1]) {
          swap(b[i], b[i + 1]);
          operations.push_back({2, i + 1});
          f = true;
        }
      }
    }
    cout << operations.size() << endl;
    for(auto i:operations){
      cout << i.first << " " << i.second << endl;
    }
  }
  return 0;
}