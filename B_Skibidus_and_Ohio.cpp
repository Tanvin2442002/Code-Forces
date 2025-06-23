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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      string s;
      cin >> s;
      bool f= false;
      for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
          f = true;
          break;
        }
      }
      if(f)cout << 1 << endl;
      else cout << s.size() << endl;
    }
    return 0;
}