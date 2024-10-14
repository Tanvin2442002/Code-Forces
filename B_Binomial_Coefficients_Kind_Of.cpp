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

const int N = 1e6 + 4;
int permutation[N];

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
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
    permutation[0] = 1;
    for(int i=1;i<N;i++){
        permutation[i] = (permutation[i-1]*2)%mod;
    }
    for(int i=0;i<n;i++){
      cout<<permutation[b[i]]<<endl;
    }
  }
  return 0;
}