#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

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

const int mod = LLONG_MAX;
int dd = 0;

double nthRoot(int A, int N)

{
    int cnt = 0;

    // initially guessing a random number between

    // 0 and 9

    double xPre = rand() % 10;



    //  smaller eps, denotes more accuracy

    double eps = 1e-3;



    // initializing difference between two

    // roots by INT_MAX

    double delX = INT_MAX;



    //  xK denotes current value of x

    double xK;



    //  loop until we reach desired accuracy

    while (delX > eps)

    {
        cnt++;
        //  calculating current value from previous

        // value by newton's method

        xK = ((N - 1.0) * xPre +

              (double)A/pow(xPre, N-1)) / (double)N;

        delX = abs(xK - xPre);

        xPre = xK;

    }

    cerr << dd++ << " cnt: " << cnt << '\n';

    return xK;

}



int power(int base, int n, int m = mod) {
  if (n == 0) return 1;
   
  if (n & 1) {
    int x = power(base, n / 2);
    if(x > (int)(1e18)) return 1e18;
    return ((x * x) % m * base) % m;
  }
  else {
    int x = power(base, n / 2);
    if(x > (int)(1e18)) return 1e18;
    return (x * x) % m;
  }
}

int binS(int a, int i, int low, int high) {
  int ans = high;
  int cnt = 0;
  while(low <= high) {
    cnt++;
    int mid = (low + high) / 2;
    int pp = power(mid, i);
    if(pp >= 1e18) {
      high = mid - 1;
      continue;
    }
    int x = abs(a - pp);
    
    int y = abs(a - power(mid - 1, i));
    if(x <= y) {
      ans = mid;
      low = mid + 1;
    }
    else high = mid - 1;
    // dbg(low, high);
  }
  // cerr << dd++ << " cnt: " << cnt << '\n';
  return ans;
}


// int mod  = 1000000007;
int inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    // freopen("output.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    while(t--){

      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0;i<n;i++) cin >> a[i];
      sort(vf(a));
      int mx = 0, mnC = INT_MAX;
      map<int, int> mp;
      for(int i=1;i<n;i++) {
        int g = 1e9;
        int x= binS(a[i], i, 1, g);
        mp[x]++;
        if(mx < mp[x]) {
            mx = mp[x];
        }
      }
      for(auto i:mp) {
        if(i.second == mx) mnC = min(mnC, i.first);
      }
      int cnt = 0;
      for(int i=0;i<n;i++) {
        cnt += abs(power(mnC, i) - a[i]);
      }
      cout << cnt << '\n';
    }
    return 0;
}
