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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>teachers(m);
        for(int i=0;i<m;i++){
            cin>>teachers[i];
        }
        sort(vf(teachers));
        while(k--){
            int x;
            cin>>x;
            int r=upper_bound(vf(teachers),x)-teachers.begin();
            int l=lower_bound(vf(teachers),x)-teachers.begin();
            // cout<<l<<" "<<r<<endl;
            if(teachers[l]>x){
            //    cout<<teachers[l]<<endl;
               l--;
            }
            if(r==teachers.size()){
                cout<<n-teachers[m-1]<<endl;
                continue;
            }
            if(teachers[l]<x && teachers[r]>x){
                int ans=teachers[r]+teachers[l];
                int mid = 0;
                if(ans%2==0){
                    mid=ans/2;
                }
                else{
                    mid=ans/2+1;
                }
                // cout<<mid<<endl;
                int mn = min(abs(mid-teachers[l]),abs(mid-teachers[r]));
                cout<<mn<<endl;
            }
            else{
                cout<<teachers[0]-1<<endl;
            }
            
            
        }



    }
    return 0;
}