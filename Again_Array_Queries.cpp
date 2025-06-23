#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(nullptr)
#define out cout.tie(nullptr)
int mod = 1000000007;
ll INF = 1e18;

int32_t main() {
    fastio; in; out;
    int t = 1;
    cin >> t;
    int cs = 1;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++){
          cin >> a[i];
        }
        vector<vector<int>> p(1001);
        for (int i = 0; i < n; i++) p[a[i]].push_back(i);
        cout << "Case " << cs++ << ":\n";
        while(q--) {
            int l, r, ans = INT_MAX, pv = -1;
            cin >> l >> r;
            for (int v = 1; v <= 1000; v++) {
                if(p[v].empty()) continue;
                auto it = lower_bound(all(p[v]), l);
                if(it != p[v].end() && *it <= r) {
                    auto it2 = upper_bound(it, p[v].end(), r);
                    if ((it2 - it) >= 2) {
                        ans = 0;
                        break;
                    }
                    if(pv != -1) ans = min(ans, v - pv);
                    pv = v;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
