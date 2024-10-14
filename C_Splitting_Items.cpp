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
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pq.push(x);
    }
    int A = 0;
    int B = 0;
    for (int i = 0; i < n; i++) {  // 8 7 4 4 3   15
      if (i % 2 == 0) {
        A += pq.top();
      } else {
        B += pq.top();
        if (A > B) {
          int x = A - B;
          if (x <= k) {
            B += x;
            k -= x;
          } else {
            B += k;
            k = 0;
          }
        }
      }
      // cerr << pq.top() << endl;
      pq.pop();
    }
    // cerr << A << " " << B << endl;
    cout << A - B << endl;
  }
  return 0;
}