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
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int x = 0;
        int res = 1;
        if (k == 1)
        {
            x = n;
        }
        else
        {
            if (n < k)
            {
                x = n;
            }
            else
            {
                while (n != 0)
                {
                    while (res * k <= n)
                    {
                        res = res * k;
                    }
                    if(res == 1){
                        break;
                    }
                    n = n - res;
                    res = 1;
                    x++;
                }
                if(n != 0){
                    x += n;
                }
            }

        }
        cout << x << endl;
    }
    return 0;
}