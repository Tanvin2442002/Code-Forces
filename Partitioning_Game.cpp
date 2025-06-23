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
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      vector<int>grundy(n);
      for(int i=0;i<n;i++){
        if(v[i]==1 or v[i]==2)grundy[i]=0;
        else if(v[i]%3==0)grundy[i]=1;
        else if(v[i]%3==1)grundy[i]=2;
        else if(v[i]%3==2)grundy[i]=0;
      }
      int ans = 0;
      for(int i=0;i<grundy.size();i++){
        ans^=grundy[i];
      }
      if(ans)cout << "Alice" << '\n';
      else cout << "Bob" << "\n";
    }
    return 0;
}