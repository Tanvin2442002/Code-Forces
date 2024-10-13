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
//  #include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e9;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int B,y;
        cin >> B >> y;
        int r = 1e9;
        int l = 0;
        int ans = inf;
        while(l<=r){
            int m = l + (r-l)/2;
            int a = floor(m/2);
            int b = m - a;
            a*=a;
            b*=b;
            int c = m*y;
            int sum = a+b+c;
            // cerr << sum << '\n';
            if(sum > B){
                r = m-1;
            }
            else{
                ans = m;
                l = m+1;
            }
        }
        cout<<(1LL << ans)<<endl;
    }
    return 0;
}