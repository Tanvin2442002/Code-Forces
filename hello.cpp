#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll k;
    cin>>k;
    for (ll t=1;t<=k;++t){
        string s1,s2;
        cin.ignore();
        getline(cin,s1);
        getline(cin,s2);
        map<char,ll>frq1,frq2;
        ll n1 = s1.length();
        ll n2 = s2.length();
        ll cnt1=0,cnt2=0;
        for(ll i=0;i<n1;++i){
            if(s1[i]!=' '){
              cnt1++;
              if(s1[i]>='A' && s1[i]<='Z'){
                frq1[(char)(s1[i]+32)]++;
              }
              else frq1[s1[i]]++;
            }
        }
        for(ll i=0;i<n2;++i){
            if(s2[i]!=' '){
                cnt2++;
                if(s2[i]>='A' && s2[i]<='Z') {
                  frq2[(char)(s2[i]+32)]++;
                }
                else frq2[s2[i]]++;
            }
        }
        for(auto it: frq1){
          if(frq2.count(it.first)){
            ll c = min(frq1[it.first],frq2[it.first]);
            cnt2-=c;
            cnt1-=c;
          }
        }
        if(cnt1==0 || cnt2==0){
            cout<<"Case "<<t<<": Yes\n";
        }
        else{
            cout<<"Case "<<t<<": No\n";
        }
    }
    return 0;
}