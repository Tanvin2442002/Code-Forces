#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define ll  long long
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

vector<int>mark;

void sett(int i,int v,int x,int lx, int rx){
  if(i<lx or i>rx) return;
  if(i==lx and i==rx){
    mark[x]=v;
    return;
  }
  int mid = (lx+rx)/2;
  sett(i,v,2*x,lx,mid);
  sett(i,v,2*x+1,mid+1,rx);
  mark[x] = mark[2*x]+mark[2*x+1];
}

int query(int l,int r,int x,int lx, int rx){
  if(l>rx or r<lx) return 0;
  if(lx>=l and rx<=r) return mark[x];
  int m = (lx+rx)/2;
  int s1 = query(l,r,2*x,lx,m);
  int s2 = query(l,r,2*x+1,m+1,rx);
  return s1+s2;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n;
      cin >> n;
      mark.assign(4*n+3,0);
      vector<int>a(n+1);
      for(int i=1;i<=n;i++){
        cin >> a[i];
      }
      for(int i=1;i<=n;i++){
        cout<<query(a[i]+1,n,1,1,n)<<" ";
        sett(a[i],1,1,1,n);
        // dbg(mark);
      }
      cout << endl;
    }
    return 0;
}