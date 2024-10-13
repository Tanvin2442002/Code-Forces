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


int mod  = 1000000007;
int inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            char a;
            cin>>a;
            if(a=='U')cnt++;
        }
        if(cnt%2==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}