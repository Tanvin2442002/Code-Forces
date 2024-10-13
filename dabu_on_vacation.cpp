#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
//  #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        float D, d, H;
        cin >> D >> d >> H;
        float radius = D / 2.0;
        float vol = (4.0 / 3.0) * (22.0 / 7.0) * radius * radius * radius;
        vol = vol / 2.0;
        float tmp = d - radius;
        float rad = sqrt(radius * radius - tmp * tmp);
        float vol2 = (22.0 / 7.0) * rad * rad * H;
        vol2 = vol2 / 2.0;
        if (abs(vol - vol2) < 0.01)
        {   
            cout <<"Case "<<cs++<<": ";
            cout << "YES" << endl;
        }
        else
        {   
            cout <<"Case "<<cs++<<": ";
            cout << "NO" << endl;
        }
    }
    return 0;
}