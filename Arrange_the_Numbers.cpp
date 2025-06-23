#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)

int mod  = 1000000007;
ll inf  = 1e18;
 
const int MAX = 1000;
 
vector<ll> fact(MAX+1), invfact(MAX+1);

ll modexp(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
 

void precomputeFactorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[n] = modexp(fact[n], mod-2); 
    for (int i = n; i >= 1; i--){
        invfact[i-1] = (invfact[i] * i) % mod;
    }
}
 

ll ncr(int n, int r){
    if(r < 0 || r > n) return 0;
    return ((fact[n] * invfact[r]) % mod * invfact[n-r]) % mod;
}
 
int32_t main()
{
    fastio; in; out;

    precomputeFactorials(MAX);
    
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        int n, m, k;
        cin >> n >> m >> k;
        ll waysFixed = ncr(m, k);
        int rem = m - k;
        ll derangeCount = 0;
        for (int j = 0; j <= rem; j++){
            ll term = ncr(rem, j);
            if(j % 2 == 1)
                term = (mod - term) % mod;
            term = (term * fact[n - k - j]) % mod;
            derangeCount = (derangeCount + term) % mod;
        }
        ll ans = (waysFixed * derangeCount) % mod;
        cout << "Case " << tc << ": " << ans << "\n";
    }
    return 0;
}
