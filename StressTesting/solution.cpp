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

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1){
      cout<<0<<endl;
      continue;
    }
    map<char, int> mp;
    string s1 = "", s2 = "";
    int id = 0;
    for (int i = 0; i < n; i++) {
      mp[s[i]]++;
      if (mp[s[i]] < 2) {
        s1 += s[i];
      } else {
        id = i;
        break;
      }
      // dbg(mp,id);
    }
    if (id != 0) {
      for (int i = id; i < n; i++) {
        s2 += s[i];
      }
    }
    set<int> st1, st2;
    for (int i = 0; i < s1.size(); i++) {
      st1.insert(s1[i]);
    }
    for (int i = 0; i < s2.size(); i++) {
      st2.insert(s2[i]);
    }
    cout << st1.size() + st2.size() << endl;
  }
  return 0;
}