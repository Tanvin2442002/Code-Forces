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
int N = 1e6 + 5;
vector<bool> prime(N, true);

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void sieve()
{
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    sieve();
    cin >> t;
    while (t--)
    {
        int n;
        int ans = INT_MAX;
        cin >> n;
        bool flag = false;
        if(n==1) cout<<1<<endl;
        else if (isPrime(n))
        {
            cout << 1 << endl;
        }
        else
        { 
            for (int i = n; i >= 1; i--)
            {
                int ans2 = 0;
                //    cout<<i<<endl;
                if (prime[i])
                {
                    int x = n - i;
                    ans2++;
                    int d = 1;
                    while (x>0)
                    {
                       x=x-d;
                       d*=2;
                       ans2++;
                    }
                    if (x == 0)
                    {
                        flag = true;
                        ans = min(ans, ans2);
                    }
                }
            }
            if (flag)
            {
                cout << ans << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}