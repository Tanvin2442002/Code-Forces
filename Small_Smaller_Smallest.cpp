#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

// #define int   long long
// #define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
// #define endl "\n"
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
      string s;
      cin >> n >> s;
      string final = "";
      for(int i=0;i<s.size();i++){
        if(s[i]=='1')final+="1";
      }
      int x = final.size();
      // cerr<<x<<endl;
      if(x==1)cout<<1<<"\n";
      else if(x>1)
      {
        if(x%2==0)cout<<0<<"\n";
        else cout<<1<<"\n";
      }
      else cout<<n<<"\n";
    }
    return 0;
}