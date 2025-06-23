#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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

vector<int>minimum;

void build(vector<int>&a,int x,int lx,int rx){
  if(lx==rx){
    minimum[x]=a[lx];
    return;
  }
  int m = (lx+rx)/2;
  build(a,2*x,lx,m);
  build(a,2*x+1,m+1,rx);
  minimum[x] = min(minimum[2*x],minimum[2*x+1]);
}

int query(int l,int r,int x,int lx,int rx){
  if(lx>r or l>rx) return inf;
  if(lx>=l and rx<=r) return minimum[x];
  int m = (lx+rx)/2;
  int mn1 = query(l,r,2*x,lx,m);
  int mn2 = query(l,r,2*x+1,m+1,rx);
  return min(mn1,mn2);
}

void sett(int i,int v,int x,int lx,int rx){
  if(lx>i or i>rx) return;
  if(lx==i and rx==i){
    minimum[x] = v;
    return;
  }
  int m = (lx+rx)/2;
  sett(i,v,2*x,lx,m);
  sett(i,v,2*x+1,m+1,rx);
  minimum[x] = min(minimum[2*x],minimum[2*x+1]);
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      ll n,m;
      cin >> n >> m;
      vector<int>a(n+1);
      for(int i=1;i<=n;i++){
        cin >> a[i];
      }
      minimum.assign(4*n+3,inf);
      build(a,1,1,n);
      while(m--){
        int x;
        cin >> x;
        if(x==1){
          int i,v;
          cin >> i >> v;
          sett(i+1,v,x,1,n);
        }
        else {
          int l,r;
          cin >> l >> r;
          l++;
          cout << query(l,r,1,1,n)<<endl;
        }
      }
    }
    return 0;
}