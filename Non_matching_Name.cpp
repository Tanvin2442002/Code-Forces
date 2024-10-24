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
    int n1, n2;
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> m1;
    for (int i = 0; i < s1.size(); i++) {
      m1[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++) {
      m1[s2[i]]++;
    }
    if(m1.size()<26)cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
