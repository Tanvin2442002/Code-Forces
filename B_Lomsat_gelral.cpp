#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


ll mod  = 1000000007;
ll inf  = 1e18;

const ll N = 2e5+3;

vector<ll>colors;
vector<ll>graph[N];
vector<ll>ans;

class node {
  public:
   map<ll,ll>freq;
   ll fmx=0;
   ll sum=0;
};

node& merge(node a,node& b){
   if(a.freq.size()>b.freq.size()){
      swap(a,b);
   }
   for(auto p:a.freq){
     b.freq[p.first]+=p.second;
     if(b.freq[p.first]>b.fmx){
        b.fmx=b.freq[p.first];
        b.sum=p.first;
     }else if(b.freq[p.first]==b.fmx){
       b.sum+=p.first;
     }
   }
   return b;
}

node dfs(ll u, ll p){
  node res;
  res.freq[colors[u]]++;
  res.fmx=1;
  res.sum=colors[u];
  for(auto v:graph[u]){
    if(v==p)continue;
    res = merge(dfs(v,u),res);
  }
  ans[u]=res.sum;
  return res;
}

int32_t main()
{
    fastio;in;out;
    ll t = 1;
    //cin >> t;
    while(t--){
      ll n;
      cin >> n;
      colors.resize(n);
      for(ll i=0;i<n;i++){
        cin >> colors[i];
      }
      for(ll i=0;i<n-1;i++){
         ll u,v;
         cin >> u >> v;
         u--,v--;
         graph[u].push_back(v);
         graph[v].push_back(u);
      }
      ans.resize(n);
      dfs(0,0);
      for(auto i:ans){
        cout << i << " ";
      }
    }
    return 0;
}