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


int mod  = 1000000007;
ll inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      string s;
      cin >> s;
      map<char,int>mp;
      for(int i=1;i<s.size()-1;i++){
        mp[s[i]]++;
      }
      bool f =false;
      for(auto i:mp){
        if(i.second>1){
          cout << "YES" << endl;
          f = true;
          break;
        }
      }
      int sz = s.size();
      if(!f){
        if(mp[s[0]]>0 or mp[s[sz-1]]>0)cout << "YES" << endl;
        else cout << "NO" << endl;
      }
    }
    return 0;
}