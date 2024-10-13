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
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;
const int N = 1e7 + 3;

vector<int> primes;
bool notprime[N];

void seive()
{
    primes.push_back(2);
    for (int i = 4; i < N; i += 2)
    {
        notprime[i] = true;
    }
    for (int i = 3; i < N; i += 2)
    {
        if (!notprime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < N; j += 2 * i)
            {
                notprime[j] = true;
            }
        }
    }
}

int32_t main()
{
    fastio;
    in;
    out;
    seive();
    freopen("prime_subtractorization_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    int cs = 1;
    while (t--)
    {
        int n;
        cin>>n;
        if(n<5){
            cout<<"Case #"<<cs++<<": "<<0<<endl;
            continue;
        }
        int lo = 0,hi = primes.size()-1;
        int ans = hi;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(primes[mid]<=n){
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1; 
            }
        }
        int cnt=0;
        for(int i=0;i<ans;i++)
        {
            int sub = primes[i+1]-primes[i];
            if(!notprime[sub]){
                cnt++;
            }
        }
        cout<<"Case #"<<cs++<<": "<<cnt<<endl;
    }
    return 0;
}