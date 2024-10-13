#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
 //#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        if(isPrime(n))cout<<n-1<<endl;
        else
        {
            int ans = inf;
            for(int i=2; i*i<=n; i++)
            {
                if(n%i == 0)
                {
                    ans = min(ans, i);
                    ans = min(ans, n/i);
                }
            }
            // int init=ans;
            int mx=ans;
            //cout<<mx<<endl;
            int j=1;
            for(int i=1;i<n;i++)
            {
                if(mx*i>=n)
                {
                    j=i;
                    break;
                }
            }
            mx=mx*j;
            mx=mx-ans;
            cout<<mx<<endl;
        }

    }
    return 0;
}