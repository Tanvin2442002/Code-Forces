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

int mod = 1000000007;
int inf = 1e18;

bool mazeOut(int i, int j, char c, int n, int m) {
  if (c == 'U')
    i--;
  else if (c == 'D')
    i++;
  else if (c == 'L')
    j--;
  else if (c == 'R')
    j++;
  return i < 0 or i >= n or j < 0 or j >= m;
}

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int x, int y, int n, int m) {
  if (visited[x][y])
    return;
  visited[x][y] = 1;
  if (y - 1 >= 0 and grid[x][y - 1] == 'R')
    dfs(grid, visited, x, y - 1, n, m);
  if (y + 1 < m and grid[x][y + 1] == 'L')
    dfs(grid, visited, x, y + 1, n, m);
  if (x - 1 >= 0 and grid[x - 1][y] == 'D')
    dfs(grid, visited, x - 1, y, n, m);
  if (x + 1 < n and grid[x + 1][y] == 'U')
    dfs(grid, visited, x + 1, y, n, m);
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int, int>> id;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (mazeOut(i, j, grid[i][j], n, m)) {
          id.push_back({i, j});
        }
      }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (auto i : id) {
      dfs(grid, visited, i.first, i.second, n, m);
    }

    dbg(visited);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
          if (i>0 and visited[i - 1][j] == 0)
            cnt++;
          else if (i+1<n and visited[i + 1][j] == 0)
            cnt++;
          else if (j>0 and visited[i][j - 1] == 0)
            cnt++;
          else if (j + 1 < m and visited[i][j + 1] == 0)
            cnt++;
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
