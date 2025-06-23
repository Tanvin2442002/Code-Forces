#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define ld long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int maxsize = *max_element(vf(a));
        sort(vf(a));
        int mexsize = 1;
        for (int sz : a) {
            if (sz == mexsize)
                mexsize++;
        }
        if(mexsize > maxsize) {
            cout << (maxsize % 2 == 1 ? "Alice" : "Bob") << "\n";
        }
        else {
            cout << (mexsize % 2 == 1 ? "Alice" : "Bob") << "\n";
        }
    }
    return 0;
}