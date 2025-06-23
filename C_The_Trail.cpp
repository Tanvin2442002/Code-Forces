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
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> rowsum(n), colsum(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    int s = 0;
    int s1 = 0;
    for (int i = 0; i < n; i++) {
      s = 0;
      for (int j = 0; j < m; j++) {
        s += grid[i][j];
      }
      rowsum[i] = s;
    }
    for (int i = 0; i < m; i++) {
      s1 = 0;
      for (int j = 0; j < n; j++) {
        s1 += grid[j][i];
      }
      colsum[i] = s1;
    }
    // dbg(rowsum);
    // dbg(colsum);
    pair<int, int> p = {0, 0};
    for (auto i : str) {
      int x = p.first;
      int y = p.second;
      if (i == 'D') {
        int rsum = rowsum[x];
        // int csum = colsum[y];
        rsum = -rsum;
        grid[x][y] = rsum;
        rowsum[x] = 0;
        colsum[y] += rsum;
        p = {x+1,y};
      } else {
        int csum = colsum[y];
        csum=-csum;
        grid[x][y]=csum;
        colsum[y]=0;
        rowsum[x]+=csum;
        p={x,y+1};
      }
    }
    int x = p.first;
    int y = p.second;
    int rsum = rowsum[x];
    rsum=-rsum;
    grid[x][y]=rsum;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout << grid[i][j] <<" ";
      }
      cout << endl;
    }
    // cout << endl;
  }
  return 0;
}