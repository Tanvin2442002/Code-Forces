#pragma GCC optimize("O3")
#include<bits/stdc++.h>

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


int mod  = 998244353;
int inf  = 1e18;

int fact(int n){
  if(n==1 or n==0)return 1;
  return (n*(fact(n-1)))%mod;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      string s;
      cin >> s;
      int cnt=1;
      vector<int>ans;
      for(int i=0;i<s.size()-1;i++){
         if(s[i]==s[i+1]){
          cnt++;
         }
         else{
           ans.push_back(cnt);
           cnt = 1;
         }
      }
      ans.push_back(cnt);
      int res = 1;
      for(int i=0;i<ans.size();i++){
        res=(res*ans[i])%mod;
      }
      int aa = accumulate(vf(ans),0LL);
      int a = s.size()-ans.size();
      cout << a << " " << (res*fact(a))%mod<<endl;
    }
    return 0;
}

