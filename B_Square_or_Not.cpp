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
        int n;
        string s;
        cin >> n >> s;
        int sqt = sqrt(n);
        int k = 2;
        int l = sqt - 1;
        if (sqt * sqt != n)
        {
            cout << "No" << endl;
        }
        else
        {
            string ans = "";
            for (int i = 0; i < sqt; i++)
            {
                for (int j = 0; j < sqt; j++)
                {
                    if (i == 0 or i == sqt - 1)
                    {
                        ans += '1';
                    }
                    else if (j == 0 or j == sqt - 1)
                    {
                        ans += '1';
                    }
                    else
                    {
                        ans += '0';
                    }
                }
            }
            if (ans == s)
            {
                cout << "Yes" << endl;
            }
            else
            {
                // cout << ans << endl;
                // cout << s << endl;
                cout << "No" << endl;
            }
        }
    }
    return 0;
}