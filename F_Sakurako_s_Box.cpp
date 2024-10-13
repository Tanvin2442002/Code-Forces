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

const int MOD = 1000000007;

int modPow(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int32_t main()
{   
    fastio;
    in;
    out;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int sumOfProducts = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum = (sum + a[i]) % MOD;
        }

        for (int i = 0; i < n; i++)
        {
            sumOfProducts = (sumOfProducts + a[i] * (sum - a[i] + MOD)) % MOD;
        }

        sumOfProducts = (sumOfProducts * modPow(2, MOD - 2, MOD)) % MOD;

        int pairs = n * (n - 1) / 2;

        int pairsInv = modPow(pairs, MOD - 2, MOD);

        int expectedValue = (sumOfProducts * pairsInv) % MOD;
        cout << expectedValue << endl;
    }
    return 0;
}
