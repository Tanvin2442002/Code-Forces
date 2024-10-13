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
        int n,k;
        cin>>n>>k;
        vector<string>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        string ans="";
        for(auto s:arr){
            for(auto c:s){
                if(c=='n' or c=='a' or c=='r' or c=='e' or c=='k'){
                    ans+=c;
                }
            }
        }
        string a="narek";
        cout<<ans<<endl;
        int cnt=0;
        for(int i=0;i<ans.size();i++){
           if(ans[i]=='n')
           {
               for(int j=i+1;j<ans.size();j++){
                   if(ans[j]=='a'){
                       for(int k=j+1;k<ans.size();k++){
                           if(ans[k]=='r'){
                               for(int l=k+1;l<ans.size();l++){
                                   if(ans[l]=='e'){
                                       for(int m=l+1;m<ans.size();m++){
                                           if(ans[m]=='k'){
                                               cnt++;
                                               
                                           }
                                       }
                                   }
                               }
                           }
                       }
                   }
               }
           }
        }
        cout<<cnt<<endl;

    }
    return 0;
}