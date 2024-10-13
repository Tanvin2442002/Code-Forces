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

const int N = 1e5 + 3;
vector<int> spf(N);
vector<int> cnt(N);

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
    int t=1;
    // cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> a >> b;
        int arr[a];
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
            int tmp = arr[i];
            while (tmp > 1)
            {
                cnt[spf[tmp]]++;
                tmp /= spf[tmp];
            }
        }
        int brr[b];
        for (int i = 0; i < b; i++)
        {
            cin >> brr[i];
            int tmp = brr[i];
            while (tmp > 1)
            {
                cnt[spf[tmp]]--;
                tmp /= spf[tmp];
            }
        }
        vector<int> num,dem;
        num.push_back(1);
        for(int i=2;i<N;i++)
        {
            while(cnt[i]>0)
            {
                num.push_back(i);
                cnt[i]--;
            }
        }

        //  int denominator = 1;
        dem.push_back(1);
        for(int i=2;i<N;i++)
        {
            while(cnt[i]<0)
            {
                dem.push_back(i);
                cnt[i]++;
            }
        }
        cout<<num.size()<<" "<<dem.size()<<endl;
        for(auto i:num)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:dem)
        {
            cout<<i<<" ";
        }
        cout<<endl;
     }

    return 0;
}
