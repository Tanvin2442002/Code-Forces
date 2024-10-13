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

const int N = 1e7 + 3;
vector<int> spf(N);   
bool isPrime[N]; 
vector<int> primes;

void sieve()
{

    for (int i = 2; i < N; ++i)
    {
        spf[i] = i;
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < N; ++i)
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
    sieve();
    int siz=primes.size();
    siz++;
    vector<int>psum(siz);
    partial_sum(vf(primes),psum.begin()+1);
    int t;
    cin >> t;
    while (t--)
    {
       int n;
       cin>>n;
       int no_of_primes=lower_bound(vf(primes),spf[n])-primes.begin();
       int spff = psum[no_of_primes+1]*n;
       cout<<spff<<endl;

    }

    return 0;
}
