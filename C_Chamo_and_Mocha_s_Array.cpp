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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b = a;
        sort(vf(b));
        if (n > 2)
        {
            int ans=0;
            for(int i=0;i<n-2;i++)
            {
                vector<int>tmp(3);
                tmp[0]=a[i];
                tmp[1]=a[i+1];
                tmp[2]=a[i+2];
                sort(vf(tmp));
                int c=tmp[1];
                ans=max(ans,c);
            }
            cout<<ans<<endl;
        }
        else
        {
            cout << b[0] << endl;
        }
    }
    return 0;
}