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
      set<int>a,b;
      map<int,int>m1,m2;
      for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.insert(x);
        m1[x]++;
      }
      for(int i=0;i<n;i++){
        int x;
        cin >> x;
        b.insert(x);
        m2[x]++;
      }
      if(a.size()>=3 or b.size()>=3)cout << "YES" << endl;
      else {
        int mn1 = 100;
        for(auto i:m1){
          mn1=min(mn1,i.second);
        }
        int mn2=100;
         for(auto i:m1){
          mn1=min(mn1,i.second);
        }
        if((mn1>=2 or mn2>=2) and (a.size()>=2 and b.size()>=2))cout << "YES" << endl;
        else cout << "NO" <<endl;
      }
    }
    return 0;
}