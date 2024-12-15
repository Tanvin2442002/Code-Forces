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
float pi=acos(-1);
int b,c;
float f(float x){
  float val=(x*x+b*x+c)/(float)sin(x);
  return val;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      cin>>b>>c;
      float lo=0, hi =pi/2.0;
      while(hi-lo>1e-10){
        float m1=lo+(hi-lo)/3;
        float m2=hi-(hi-lo)/3;
        if(f(m1)<f(m2)) hi=m2;
        else lo=m1;
      }
      cout<<fixed<<setprecision(10)<<f(lo)<<endl;
    }
    return 0;
}