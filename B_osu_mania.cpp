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
        int n;
        cin>>n;
        char arr[n][4];
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='#'){
                    ans.push_back(j);
                }
            }
        }
        reverse(vf(ans));
        for(auto x:ans){
            cout<<x+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}