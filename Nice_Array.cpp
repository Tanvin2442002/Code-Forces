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
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < 0)
        neg.push_back(x);
      else
        pos.push_back(x);
    }
    int negSum = 0;
    int cntneg = 0;
    for (int i = 0; i < neg.size(); i++) {
      negSum += (neg[i] / k);
      if (neg[i] % k != 0)
        cntneg++;
    }
    negSum = abs(negSum);
    int posSum = 0;
    int cntpos = 0;
    for (int i = 0; i < pos.size(); i++) {
      posSum += (pos[i] / k);
      if (pos[i] % k != 0)
        cntpos++;
    }
    int diff = abs(posSum - negSum);
    if (negSum > posSum) {
      if (cntpos >= diff)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    } else {
      if (cntneg >= diff)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}