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

int power(int base, int n, int m = mod) {
  if (n == 0) return 1;
  if (n & 1) {
    int x = power(base, n / 2);
    return ((x * x) % m * base) % m;
  }
  else {
    int x = power(base, n / 2);
    return (x * x) % m;
  }
}


int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      int x = log10(n);
      int val = power(10,x);
      // cout<<" val " <<val<<endl;
      cout << n - val <<endl;
    }
    return 0;
}