#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
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
int n;

int calc(int n) {
  return n * (n + 1) / 2;
}

int BinSearch(int start, vector<int>& prefix, vector<int>& sum1, vector<int>& sum2) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi + 1) >> 1;
    if ((calc(n) - calc(n - mid)) <= start)
      lo = mid;
    else
      hi = mid - 1;
  }
  int ans = sum1[lo];
  start -= calc(n) - calc(n - lo);
  lo++;
  // dbg(lo, ans);
  cerr<<"--------------"<<endl;
  dbg(prefix,sum1,sum2,ans,start);
  cerr<<"--------------"<<endl;
  ans += sum2[lo] - sum2[lo + start] - (n - lo + 1 - start) * (prefix[lo + start - 1] - prefix[lo - 1]);
  dbg(ans,sum2[lo],sum2[lo+start],(n-lo+1-start),prefix[lo+start-1],prefix[lo-1]);
  cerr<<endl;
  cerr<<endl;
  return ans;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<int> prefix(n + 1, 0);
    prefix[0] = v[0];
    int total = v[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + v[i];
      total += prefix[i];
    }

    vector<int> ns(n + 1), nps(n + 1);
    int sum = accumulate(prefix.begin(), prefix.end(), 0LL);
    ns[0] = 0;
    for (int i = n; i > 0; i--) {
      ns[i] = sum;
      sum -= (v[n - i] * i);
    }
    nps[0] = ns[n];
    for (int i = n - 1; i > 0; i--) {
      nps[n - i] = nps[n - i - 1] + ns[i];
    }
    reverse(vf(ns));
    for (int i = n; i >= 1; i--) {
      ns[i] = ns[i - 1];
      nps[i] = nps[i - 1];
      prefix[i] = prefix[i - 1];
    }
    ns[0] = 0;
    nps[0] = 0;
    prefix[0] = 0;
    // dbg(ns, nps, prefix);
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      int ans = BinSearch(r, prefix, nps, ns) - BinSearch(l - 1, prefix, nps, ns);
      cout << ans << endl;
    }
  }
  return 0;
}
