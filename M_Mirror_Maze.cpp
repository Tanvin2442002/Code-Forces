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

int cnt;
int n, m;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int reflect(int dir, char mirror) {
  if (mirror == '/') {
    if (dir == 0)
      return 2;
    if (dir == 1)
      return 3;
    if (dir == 2)
      return 0;
    if (dir == 3)
      return 1;
  } else if (mirror == '\\') {
    if (dir == 0)
      return 3;
    if (dir == 1)
      return 2;
    if (dir == 2)
      return 1;
    if (dir == 3)
      return 0;
  }
  return dir;
}
void dfs(int x, int y, vector<vector<int>> &visited, vector<vector<char>> &grid, int dir, int &mirrorCount, vector<vector<int>> &mark) {
  dbg(x, y, mirrorCount, dir);

  if (!isValid(x, y) || visited[x][y] >= 2)
    return;

  visited[x][y]++;

  if (grid[x][y] == '/' || grid[x][y] == '\\') {
    if (mark[x][y] == 0) {
      mirrorCount++;
      mark[x][y] = 1;
    }
    dir = reflect(dir, grid[x][y]);
  }
  int nx = x + dx[dir];
  int ny = y + dy[dir];
  dfs(nx, ny, visited, grid, dir, mirrorCount, mark);
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    // vector<vector<int>>visited(n,vector<int>(m));
    set<pair<int,int>>st;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (i == 0 and j >= 0 and j <= m - 1)
          st.insert({i, j});
        if (i == n - 1 and j >= 0 and j <= m - 1)
          st.insert({i, j});
        if (i > 0 and i < n - 1 and (j == 0 or j == m - 1)) {
          st.insert({i, j});
        }
        if (grid[i][j] == '\\' or grid[i][j] == '/') {
          cnt++;
        }
      }
    }
    vector<pair<int,int>>id;
    for(auto i:st){
      id.push_back(i);
    }
    dbg(id);
    if (n == 1 and m == 1 and grid[0][0] != '.') {
      cout << 4 << endl;
      cout << "N1 E1 W1 S1" << endl;
      continue;
    }
    int sz = id.size();
    vector<bool> check(sz);
    vector<string> res;
    for (int i = 0; i < id.size(); i++) {
      if (!check[i]) {
        int x = id[i].first, y = id[i].second;
        // dbg(x,y);
        vector<int> validDirs;
        if (x == 0 and y > 0 and y < m - 1)  // 0->N 1->S 2->W 3->E
          validDirs = {1};
        else if (x == 0 and y == 0)
          validDirs = {1, 2};
        else if (x == 0 and y == m - 1)
          validDirs = {1, 3};
        else if (y == 0 and x > 0 and x < n - 1)
          validDirs = {2};
        else if (y == 0 and x == n - 1)
          validDirs = {0, 2};
        else if (y == m - 1 and x == n - 1)
          validDirs = {3, 0};
        else if (y == m - 1 and x > 0 and x < n - 1)
          validDirs = {3};
        else if (x == n - 1 and y > 0 and y < m - 1)
          validDirs = {0};
        for (int dir : validDirs) {
          vector<vector<int>> visited(n, vector<int>(m, 0));
          vector<vector<int>> mark(n, vector<int>(m, 0));
          int mirrorCount = 0;
          dbg(x, y, dir);
          dfs(x, y, visited, grid, dir, mirrorCount, mark);
          if (mirrorCount == cnt) {
            string pos;
            if (x == 0 and dir == 1) {
              pos += ('N' + to_string(y + 1));
            } else if (x == 0 and dir == 3)
              pos += ('E' + to_string(x + 1));
            else if (x == 0 and dir == 2)
              pos += ('W' + to_string(x + 1));
            else if (x > 0 and x < n - 1 and dir == 2)
              pos += ('W' + to_string(x + 1));
            else if (x > 0 and x < n - 1 and dir == 3)
              pos += ('E' + to_string(x + 1));
            else if (x == n - 1 and dir == 0)
              pos += ('S' + to_string(y + 1));
            else if (x == n - 1 and dir == 2)
              pos += ('W' + to_string(x + 1));
            else if (x == n - 1 and dir == 3)
              pos += ('E' + to_string(x + 1));
            dbg(mirrorCount, cnt, dir,pos);
            res.push_back(pos);
          }
        }
        // dbg(visited);
      }
      check[i] = true;
    }
    cout << res.size() << "\n";
    for (const string &pos : res) {
      cout << pos << " ";
    }
    cout << "\n";
  }
  return 0;
}