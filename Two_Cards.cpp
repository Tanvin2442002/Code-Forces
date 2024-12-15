#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else 
// #define dbg(x...)
// #define dbgc(x...)
// #endif
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

bool compare(pair<int,pair<int,int>>&a , pair<int,pair<int,int>>&b){
    int x = max(a.second.first,a.second.second);
    int y = max(b.second.first,b.second.second);
    return x>y;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int>a(n),b(n);
    priority_queue<pair<int,int>>pq;
    for(int i=0; i<n; ++i) {
      cin>>a[i];
      pq.push({a[i],i});
    }
    for(int i=0; i<n; ++i) {
      cin>>b[i];
    }
    bool possible=false;
    for(int i=0; i<n; ++i){
      pair<int,int> x={a[i],i};
      if(x==pq.top()){
        pq.pop();
        pair<int,int> bob=pq.top();
        pq.push(x);
        int mxa=max(a[x.second],b[x.second]);
        int mxb=max(b[bob.second],a[bob.second]);
        if(mxa>mxb) {
          possible=true;
          break;
        }
      }
      else
      {
        int mxa=max(a[i],b[i]);
        int mxb=max(a[x.second],b[x.second]);
        if(mxa>mxb){
          possible=true;
          break;
        }
      }
    }
    if(possible){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}