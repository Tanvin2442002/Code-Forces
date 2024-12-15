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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      map<int,int>mp;
      vector<int>v;
      for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mp[x]++;
      }
      for(auto i:mp){
        // dbg(i.second);
        v.push_back(i.second);
      }
      sort(vf(v));
      int alice = 0;
      for(int i=0;i<v.size();i++){
        if(i%2==0){
          if(v[i]==1)alice+=2;
          else alice++;
        }
        v[i]--;
      }
      // dbg(v);
      dbg(alice);
      int sz = v.size();
      int cnt = 0;
      if(sz%2==0){
        for(int i=0;i<v.size();i++){
          if(v[i]>0)cnt++;
        }  // cout << alice << endl;
        if(cnt%2==1){
          alice+=(cnt/2)+1;
        }
        else alice+=(cnt)/2;
      }
      else {
        for(int i=0;i<v.size();i++){
          if(v[i]>0)cnt++;
        }
        // cout << alice << endl;
        alice+=(cnt)/2;
        
      }
      cout << alice << endl;
    }
    return 0;
}