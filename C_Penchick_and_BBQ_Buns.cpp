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
      if(n==1 or n==3 or n==5 or n==7){
        cout<<"-1"<<endl;
        continue;
      }
      int cnt = 0;
      if(n%2==1){
        vector<int>v = {1, 2, 2, 3 ,1 ,4, 4, 3, 1};
        int sz = v.size();
        int p = 5;
        for(int i = sz ; i<n;i++)
        {
          v.push_back(p);
          cnt++;
          if(cnt == 2){ 
            p++;
            cnt = 0;
          }
        }
        for(auto i:v){
          cout << i <<" ";
        }
      }
      else{
        int p = 1;
        for(int i=0;i<n;i++){
          cout<<p<<" ";
          cnt++;
          if(cnt == 2){
            p++;
            cnt = 0;
          }
        }
      }
      cout<<endl;
    }
    return 0;
}