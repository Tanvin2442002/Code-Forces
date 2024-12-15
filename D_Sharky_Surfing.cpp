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
    int n, m, l;
    cin >> n >> m >> l;
    priority_queue<int> pq;
    vector<pair<int, int>> required(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      required[i] = {x, y};
    }
    vector<pair<int,int>>powers(m);
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      powers[i]={x,y};
    }
    int j = 0;
    int sum = 1;
    int cnt = 0;
    bool flag = true;
    for(int i=0;i<n;i++){
      int diff = 2 + (required[i].second-required[i].first);
      while(powers[j].first<required[i].first and j<m){
        pq.push(powers[j].second);
        j++;
      }
      while(!pq.empty() and sum<diff){
        sum+=pq.top();
        cnt++;
        pq.pop();
      }
      if(sum<diff){
        flag = false;
        break;
      }
    }
    if (!flag)
      cout << -1 << endl;
    else
      cout << cnt << endl;
  }
  return 0;
}