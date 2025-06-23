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
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), diff(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int cnt = 0;
    int cntzero = 0;
    for (int i = 0; i < n; i++) {
      diff[i] = a[i] - b[i];
      if (diff[i] < 0)
        cnt += diff[i];
      // else if(diff[i]==0)cntzero++;
    }
    vector<int> neg;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      // cerr << mn << " " << diff[i] << endl;
      if (diff[i] < 0)
        neg.push_back(diff[i]);
      else {
        mn = min(mn, diff[i]);
      }
    }
    cnt*=-1;
    if (neg.size() > 1)
      cout << "NO" << endl;
    else {
      if (cnt <= mn and cntzero <= 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}