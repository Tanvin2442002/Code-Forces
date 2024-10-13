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
//  #include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
        int n,d,k;
        cin >> n >> d >> k;
        map<int, int> m;
        for(int i = 0; i < d; i++){
            int x,y;
            cin >> x >> y;
            m[x]++;
            m[y+1]--;
        }
        int mx = 0;
        int mn = INT_MAX;
        int cnt = 0;
        int ans = 0;
        int another = 0;
        int idx = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            another =0;
            for(auto it1 = it; it1 != m.end(); it1++){
                if(cnt == k-1 )
                {
                    break;
                }
                auto it2 = next(it1); 
                if(it1->second!=it2->second){
                    another++;
                    if(another > ans)
                    {
                        ans = another;
                        idx = it1->first;
                    }
                }
            }
        }
        cout<<idx - ans<<endl;
    }
    return 0;
}