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

ll sumLR(ll L, ll R) {
    ll cnt = (R - L + 1) % mod;
    ll s = ((L % mod) + (R % mod)) % mod;
    if (cnt % 2 == 0) {
        cnt /= 2;
    } else {
        s = (s * ((mod + 1) / 2)) % mod;
    }
    return (cnt * s) % mod;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll M = min(n, m);
    ll T = 0;
    for (ll i = 1; i <= M; ) {
        ll q = n / i;
        ll last = n / q;
        if (last > M) last = M;
        ll block = sumLR(i, last);
        T = (T + (q % mod) * block) % mod;
        i = last + 1;
    }
    ll part1 = ((M % mod) * (n % mod) - T) % mod;
    if (part1 < 0) part1 += mod;
    ll part2 = 0;
    if (m > n) {
        ll extra = (m - n) % mod;
        part2 = (extra * (n % mod)) % mod;
    }
    cout << (part1 + part2) % mod << "\n";
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      solve();
    }
    return 0;
}