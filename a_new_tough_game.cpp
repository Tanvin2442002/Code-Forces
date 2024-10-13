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

int F(string Q) {
    int answer = 0;
    cout<<"?";
    cout<<" "<<Q;
    cin>>answer;
    return answer;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = "";
        for(int i=0;i<n;i++){
            s+="z";
        }
        int res = F(s);
        int ans;
        for(int i=0;i<n;i++){
            s[i]='a';
            ans = F(s);
            int diff = res - ans;
            int diff2 = 25 - diff;
            diff2 = diff2/2;
            s[i]=char('a'+diff2);
            res = res - 25 + diff2;
        }
        cout<<"!";
        cout<<" "<<s<<endl;
    }
    return 0;
}