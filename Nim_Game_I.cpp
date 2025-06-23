#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
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
    // vector<int>v(n);
    int xr = 0;
    set<int> st;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      st.insert(x);
      xr ^= x;
    }
    if (st.size() == 1 and *(st.begin()) == 1) {
      if (n % 2 == 0)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    } else {
      if (xr)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }
  }
  return 0;
}