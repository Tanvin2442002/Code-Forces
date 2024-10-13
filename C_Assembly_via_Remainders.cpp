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
// vector<int> calculate_a(vector<int>& x) {
//     int n = x.size() + 1;
//     vector<int> a(n);

//     a[0] = 1;

//     for (int i = 1; i < n; ++i) {
//         a[i] = x[i - 1] + a[i - 1];
//     }

//     return a;
// }
int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> x[i];
        }
        vector<int> a(n);
        a[n-1]=1e9;
        for(int i=n-2;i>=0;i--)
        {
            a[i]=a[i+1] - x[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}