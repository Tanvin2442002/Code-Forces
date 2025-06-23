#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
ll inf = 1e18;

vector<vector<int>> graph;
vector<int> v;
vector<bool> visited;
set<int> one;
set<int> two;

void dfs(int start) {
  visited[start] = true;
  if (v[start] == 0)
    v[start] = 1;
  for (auto i : graph[start]) {
    if (!visited[i]) {
      if (v[start] == 1) {
        v[i] = 2;
      }
      else v[i] = 1;
      dfs(i);
    }
  }
  return;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  //cin >> t;
  while (t--) {
    int n;
    cin >> n;
    // vector<int>nodes(n);
    v.resize(n + 1);
    visited.resize(n + 1);
    graph.resize(n+1);
    set<int> nodes;
    for (int i = 0; i <n-1; i++) {
      int u, v;
      cin >> u >> v;
      nodes.insert(u);
      nodes.insert(v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int start = *(nodes.begin());
    dfs(start);
    //dbg(visited);
    for(int i=1;i<n+1;i++){
      if(v[i]==1)one.insert(i);
      else two.insert(i);
    }
    ll cnt = 0;
    if(one.size()<two.size()){
       for(auto i:one){
          ll s = graph[i].size();
          cnt+=(two.size()-s);
       }
    }
    else {
      for(auto i:two){
          ll s = graph[i].size();
          cnt+=(one.size()-s);
       }
    }
    cout << cnt << endl;
  }
  return 0;
}