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

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
       int n;
        cin >> n;
        vector<pair<ll,ll>> pts(n);
        map<ll,int> cntX, cntY;
        for(int i = 0; i < n; i++){
            cin >> pts[i].first >> pts[i].second;
            cntX[pts[i].first]++;
            cntY[pts[i].second]++;
        }

        if(n <= 2){
            if(n==1)cout << 1 << "\n";
            else cout << 2 << "\n";
            continue;
        }

        auto itx = cntX.begin();
        ll min1x = itx->first;
        ll cntMin1x = itx->second;
        ++itx;
        ll min2x;
        if(itx == cntX.end()){
            min2x = min1x;
        } else {
            min2x = itx->first;
        }

        auto itx2 = cntX.end();
        --itx2;
        ll max1x = itx2->first;
        ll cntMax1x = itx2->second;
        --itx2;

        ll max2x;
        if(itx2 == cntX.begin() and itx2->first == max1x){
            max2x = max1x;
        } else {
            max2x = itx2->first;
        }


        auto ity = cntY.begin();
        ll min1y = ity->first;
        ll cntMin1y = ity->second;
        ++ity;

        ll min2y;
        if(ity == cntY.end()){
            min2y = min1y;
        } else {
            min2y = ity->first;
        }

        auto ity2 = cntY.end();
        --ity2;
        ll max1y = ity2->first;
        ll cntMax1y = ity2->second;
        --ity2;

        ll max2y;
        if(ity2 == cntY.begin() and ity2->first == max1y){
            max2y = max1y;
        } else {
            max2y = ity2->first;
        }


        ll ans = LLONG_MAX;

        for(auto &p : pts){
            ll x = p.first;
            ll y = p.second;

            ll lx = min1x;
            ll hx = max1x;
            if(x == min1x and cntMin1x == 1){
                lx = min2x;
            }
            if(x == max1x and cntMax1x == 1){
                hx = max2x;
            }

            ll ly = min1y;
            ll hy = max1y;
            if(y == min1y and cntMin1y == 1){
                ly = min2y;
            }
            if(y == max1y and cntMax1y == 1){
                hy = max2y;
            }
            ll w = hx - lx + 1;
            ll h = hy - ly + 1;
            ll area = w * h;

            ll cost;
            if(area > n - 1){
                cost = area;
            } else {
                ll xbarbe = (w + 1) * h;
                ll ybarbe = w * (h + 1);
                cost = min(xbarbe, ybarbe);
            }

            ans = min(ans, cost);
        }

        cout << ans << "\n";
    }
    return 0;
}