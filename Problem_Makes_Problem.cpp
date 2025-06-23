#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)

const int mod = 1000000007;
const ll inf = 1e18;

const int N = 2000006;  
vector<ll> fact(N + 1), inverseFact(N + 1);

ll power(ll base, ll n, ll m = mod) {
    if(n == 0) return 1;
    ll x = power(base, n / 2, m);
    if(n & 1)
        return (((x * x) % m) * base) % m;
    else
        return (x * x) % m;
}

int main() {
    fastio; in; out;
    int t = 1;
    cin >> t;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inverseFact[N] = power(fact[N], mod - 2, mod);
    for (int i = N; i >= 1; i--) {
        inverseFact[i - 1] = (inverseFact[i] * i) % mod;
    }
    
    int cs = 1;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int N = n + k - 1;  
        int r = k - 1;     
        ll ans = (fact[N] * ((inverseFact[r] * inverseFact[N - r]) % mod)) % mod;
        cout << "Case " << cs++ << ": " << ans << '\n';
    }
    return 0;
}
