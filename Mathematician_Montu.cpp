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
int N = 1000001;

int seive[1000001];

bitset<1000001> isPrime;
vector<int> primes;

void seivee()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    seivee();
    int cs = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        vector<int> b;
        int ans = 0;
        int j = 1;
        for (int i = 0; i < m; i++)
        {
            ans = 0;
            j = 1;
            if (a[i] == 1)
            { 
                for(int l = 0;l<primes.size();l++)
                {
                    if(primes[l] <= n)
                    {
                        ans++;
                    }
                }
                b.push_back(ans);
            }
            else
            {
                int k = a[i];
                while (k <= n)
                {   
                    cerr<<"k :"<<k<<endl;
                    if (__gcd(k, n) == a[i])
                    {
                        ans++;
                        cerr<<"gcd"<<" "<<__gcd(k,n)<<endl;
                    }
                    j++;
                    k = a[i] * j;
                }
                b.push_back(ans);
            }
        }
        cerr<<endl;
        cerr<<endl;
        cout<<"case "<<cs++<<": ";
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}



// 2 3 5 7 11 13 17 19 23 29