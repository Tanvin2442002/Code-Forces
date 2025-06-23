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
ll inf  = 1e18;

vector<pair<ll,ll>>minimum;

pair<ll, ll> pull(pair<ll, ll> left, pair<ll, ll> right) {
  ll mn = min(left.first, right.first);
  ll cnt = 0;
  if (mn == left.first) cnt += left.second;
  if (mn == right.first) cnt += right.second;
  return {mn, cnt};
}

void build(vector<ll>&a,ll x,ll lx,ll rx){
  if(lx==rx){
    minimum[x].first=a[lx];
    minimum[x].second=1;
    return;
  }
  ll m = (lx+rx)/2;
  build(a,2*x,lx,m);
  build(a,2*x+1,m+1,rx);
  minimum[x] = pull(minimum[2 * x], minimum[2 * x + 1]);
}

pair<ll,ll> query(ll l,ll r,ll x,ll lx,ll rx){
  if(l>rx or r<lx)return {inf,0};
  if(lx>=l and rx<=r) return minimum[x];
  ll mid = (lx+rx)/2;
  pair<ll,ll>p1 = query(l,r,2*x,lx,mid);
  pair<ll,ll>p2= query(l,r,2*x+1,mid+1,rx);
  return pull(p1, p2);
}

void sett(ll i,ll v,ll x,ll lx, ll rx){
  if(i<lx or i>rx)return;
  if(lx==i and rx==i){
    minimum[x]={v,1};
    return;
  }
  ll m = (lx+rx)/2;
  sett(i,v,2*x,lx,m);
  sett(i,v,2*x+1,m+1,rx);
  minimum[x] = pull(minimum[2 * x], minimum[2 * x + 1]);
}

int32_t main()
{
    fastio;in;out;
    ll t = 1;
    //cin >> t;
    while(t--){
      ll n,m;
      cin >> n >> m;
      minimum.assign(4*n+3,{inf,0});
      vector<ll>a(n+1);
      for(ll i=1;i<=n;i++){
        cin >> a[i];
      }
      build(a,1,1,n);
      while(m--){
        ll x;
        cin >> x;
        if(x==1){
          ll i,v;
          cin >> i >> v;
          sett(i+1,v,1,1,n);
        }
        else {
          ll l,r;
          cin >> l >> r;
          l++;
          pair<ll,ll>p=query(l,r,1,1,n);
          cout << p.first <<" "<<p.second<<endl;
        }
      }
    }
    return 0;
}