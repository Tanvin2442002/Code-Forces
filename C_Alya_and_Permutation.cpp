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
    if (n % 2 == 1) {
      vector<int> a(n);
      a[n - 1] = n;
      a[n - 2] = n - 1;
      a[n - 3] = 1;

      int c = 2;
      for (int i = 0; i < n - 5; i++) {
        a[i] = c;
        c++;
      }
      int first = n-5;
      int second = n-4;
      if(first%2==0){
        a[first] = c;
        a[second] = c+1;
      }
      else{
        a[first] = c+1;
        a[second] = c;
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
          ans |= (a[i]);
        else
          ans &= (a[i]);
      }
      cout << ans << endl;
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << "\n";
    } else {
      int var = log2(n);
      int val = pow(2, var) - 1;
      vector<int> a(n);
      a[n - 1] = n;
      a[n - 2] = val;
      a[n - 3] = val - 1;
      a[n - 4] = 1;
      int c = 2;
      for (int i = 0; i < n - 4; i++) {
        if(c==val-1){
          c = val + 1;
        }
        a[i] = c;
        c++;
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0)
          ans |= (a[i]);
        else
          ans &= (a[i]);
      }
      cout << ans << endl;
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}