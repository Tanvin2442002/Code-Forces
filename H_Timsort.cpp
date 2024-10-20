#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

const int N = 1e6 + 5;
int arr[N], seg[N << 2LL];

void build(int node, int l, int r) {
  if( l == r) {
    seg[node] = arr[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(node << 1LL, l, mid);
  build(node << 1LL | 1LL, mid + 1, r);
  seg[node] = min(seg[node << 1LL], seg[node << 1LL | 1LL]);
}

int query(int node, int l, int r, int ql, int qr) {
  if( l > qr || r < ql) return inf;
  if( l >= ql && r <= qr) return seg[node];
  int mid = (l + r) >> 1;
  return min(query(node << 1LL, l, mid, ql, qr), query(node << 1LL | 1LL, mid + 1, r, ql, qr));
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      for(int i=0;i<N;i++) arr[i] = inf;
      int n;
      cin >> n;
      vector<int> a(n + 1);
      for(int i=1;i<=n;i++) cin >> a[i];
      int i = 1;
      while(i + 1 <= n) {
        int j = i + 1;
        if(a[j] >= a[i]) {
          while(j <= n && a[j] >= a[j-1]) j++;
        }
        else {
          while(j <= n && a[j] < a[j-1]) j++;
        }
        arr[j] = j;
        dbg(j);
        i = j;
      }
      build(1, 1, n);
      int q;
      cin >> q;
      vector<int> qu(q + 1);
      vector<pair<int, int>> ans(q + 1);
      map<int, vector<int>> mp;
      for(int i=1;i<=q;i++) {
        cin >> qu[i];
        mp[qu[i]].push_back(i);
      }
      for(auto &x: mp) {
        int rg = x.first;
        int cnt = 0, div = 0;
        int ind = 1;
        while(ind <= n) {
          int mnInd = query(1, 1, n, ind + 1, n);
          div++;
          if(mnInd == inf) {
            break;
          }
          dbg(mnInd);
          if(mnInd - 1 == ind) mnInd++;
          if(mnInd - ind > rg) {
            ind = mnInd;
          }
          else {
            cnt += min(rg, n - ind + 1);
            cnt -= mnInd - ind;
            ind += rg;
          }
          
          dbg(ind, cnt, div);
        }
        for(auto &y: x.second) ans[y] = {div, cnt};
      }
      for(int i=1;i<=q;i++) cout << ans[i].first << " " << ans[i].second << endl;

    }
    return 0;
}