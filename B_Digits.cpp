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
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    if (n >= 9 and k % 5 == 0)
      cout << 1 << " " << 3 << " " << 5 << " " << 7 << " " << 9 << endl;
    else if (n >= 9 and k % 5 != 0)
      cout << 1 << " " << 3 << " " << 7 << " " << 9 << endl;
    else {
      ans.push_back(1);
      if (n >= 3 or k % 3 == 0)
        ans.push_back(3);
      if (k == 5)
        ans.push_back(5);
      if (n >= 3 or k == 7)
        ans.push_back(7);
      if (n >= 6 or k == 9 or (n>=3 and (k==3 or k==6)))
        ans.push_back(9);
      // else if(n==3 and (k==3 or k==6))ans.push_back(9);
      sort(vf(ans));
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}