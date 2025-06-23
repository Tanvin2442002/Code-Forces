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
      int n,a,b,c;
      cin >> n >> a >> b >> c;
      int sum = a + b + c;
      int ans = n/sum;
      ans*=3;
      int arr[3] = {a,b,c};
      int j = 0;
      int rest = n%sum;
      int s = 0;
      for(int i=ans;i<n;i++){
          if(s>=rest)break;
          s+=arr[j];
          ans++;
          j++;
      }
      cout << ans << endl;
    }
    return 0;
}