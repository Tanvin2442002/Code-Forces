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
      int n;
      cin >> n;
      vector<int>grundy(n+5);
      vector<int>moves={2,3,5};
      grundy[0]=grundy[1]=0;
      grundy[2]=grundy[3]=grundy[4]=1;
      for(int i=5;i<=n;i++){
         vector<int>v;
         for(int j=0;j<moves.size();j++){
            int k = i - moves[j];
            v.push_back(grundy[k]);
         }
         sort(vf(v));
         int a = v.front();
         int b = v.back();
         if(a==b and a==1)grundy[i]=0;
         else if(a==b and a==0)grundy[i]=1;
         else if(a!=b){
           int mx = max(a,b);
           int mn = min(a,b);
           if(mn==0 and mx==2)grundy[i]=1;
           else if(mn==1 and mx==2)grundy[i]=0;
           else if(mn==0 and mx==1)grundy[i]=2;
         }
      }
     // dbg(grundy);
      if(grundy[n])cout << "First" << endl;
      else cout << "Second" << endl;
    }
    return 0;
}