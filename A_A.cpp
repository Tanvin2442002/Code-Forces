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
int dp[10005][15];

int f(int n, int p, int m) {
    if(n == 0) {
        return 1;
    }
    if(dp[n][p] != -1) return dp[n][p];
    int cnt = 0;
    int x = log2(n) / log2(m);
    x = min(x, p);
    for(int i =x ; i>=0;i--) {
        int y = 1;
        for(int j = 1; j <= i; j++) y *= m;
        cnt += f(n - y, i, m);
    }
    return dp[n][p] = cnt;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int k, m, n;
        cin >> k >> m >> n;
        int x = log(n) / log(m);
        memset(dp, -1, sizeof dp);
        cout << k << ' ' << f(n, x, m) << '\n';
    }
    return 0;
}
