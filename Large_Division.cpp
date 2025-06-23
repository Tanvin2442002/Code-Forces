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
    int cs = 1;
    while(t--){
      string s;
      ll d ;
      cin >> s;
      reverse(vf(s));
      if(s.back()=='-')s.pop_back();
      reverse(vf(s));
      cin >> d;
      d = abs(d);
      ll rem = 0;
      for(auto i: s){
        //dbg(rem);
        rem = (rem*10 + (i-'0'));
        rem = rem%d;
      }
      //dbg(rem);
      if(rem) cout <<  "Case " << cs++ <<": " << "not divisible" << '\n';
      else cout <<  "Case " << cs++ <<": " << "divisible" << '\n';
    }
    return 0;
}