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

int mex(vector<int> &a) {
  vector<bool> f(a.size() + 1, 0);
  for (int i : a)
    if (i <= (int)a.size())
      f[i] = 1;
  int mex = 0;
  while (f[mex]) ++mex;
  return mex;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> moves(k);
    for (int i = 0; i < k; i++) {
      cin >> moves[i];
    }
    vector<int> grundy(n + 5);
    grundy[0] = 0;
    for (int i = 1; i <= n; i++) {
      vector<int> numbers;
      for (int j = 0; j < k; j++) {
        int m = i - moves[j];
        if (m >= 0)
          numbers.push_back(grundy[m]);
      }
      int r = mex(numbers);
      grundy[i] = r;
    }
    for (int i = 1; i <= n; i++) {
      if (grundy[i])
        cout << "W";
      else
        cout << "L";
    }
    cout << endl;
  }
  return 0;
}