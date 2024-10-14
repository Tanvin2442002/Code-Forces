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
    vector<int> a(n);
    map<int, int> mp;
    set<int> st;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    sort(vf(a));
    vector<int> predif(n - 1);
    for (int i = 1; i < n; i++) {
      predif[i - 1] = a[i] - a[i - 1];
    }
    for (int i = 0; i < n; i++) {
       st.insert(a[i]);
    }
    vector<int> prefix(n + 1, 0);
    auto it = st.begin();
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + mp[*it];
      it++;
      if (it == st.end()) {
        break;
      }
    }
    
    vector<int> temp;
    for (auto i : st) {
      temp.push_back(i);
    }
    // for (int i : prefix) {
    //   cerr << i << " ";
    // }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < st.size(); i++) {
      int l = i, r = min(i + k - 1, (int)st.size() - 1);
      while (l <= r) {
        // cerr << l << ' ' << r << '\n';
        int mid = (l + r) / 2;
        if (temp[mid] - temp[i] == mid - i) {
          l = mid + 1;
          ans = mid;
        } else
          r = mid - 1;
      }
      // cerr << i << " " << ans << "\n";
      // cerr << "-------------------\n";
      sum = max(sum, prefix[ans + 1] - prefix[i]);
      // cerr << "sum:" << sum << "\n";
    }
    cout << sum << endl;
  }
  return 0;
}