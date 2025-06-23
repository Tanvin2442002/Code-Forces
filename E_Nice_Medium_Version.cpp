
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false),
#define in cin.tie(NULL),
#define out cout.tie(NULL)

int mod = 1000000007;
int inf = 1e18;

int32_t main()
{
    fast in out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        string l,r;
        cin >> l >> r;
        string binL="";
        string binR="";
        //bool f = false;
        int i = 0;
        int n = l.size();
        while(i<n and (l[i]-'0'==9 or l[i]-'0'==6))
        {
            if(l[i]-'0'==9)
            {
                binL+='1';
            }
            else
            {
                binL+='0';
            }
            i++;
        }
        if(l[i]-'0'<6)
        {
            for(int j=i; j<l.size(); j++)
            {
                binL+='0';
            }
        }
        else
        {   
            binL+='1';
            i++;
            for(int j=i; j<l.size(); j++)
            {
                binL+='0';
            }
        }
        i = 0;
        int sz = r.size();
        while(i<sz and (r[i]-'0'==9 or r[i]-'0'==6))
        {
            if(r[i]-'0'==6)
                binR+='0';
            else
                binR+='1';
            i++;
        }
        if(i<sz)
        {
            if(r[i]-'0'<6)
            {
                //cout<<"ekhane"<<endl;
                bool ff = false;
                int id = 0;
                if(i!=0)
                {
                    for(int j=binR.size()-1; j>=0; j--)
                    {
                        if(binR[j]=='1')
                        {
                            binR[j]='0';
                            // binR[j+1]='1';
                            ff = true;
                            id = j;
                            break;
                        }
                        else binR[j]='1';
                    }
                }
                if(!ff)
                {
                    binR="";
                    for(int j=0; j<sz-1; j++)
                    {
                        binR+='1';
                    }
                }
                else
                {
                    int cr = binR.size();
                    for(int j=0; j<sz-cr; j++)
                    {
                        binR+='1';
                    }
                }
            }
            else
            {
                binR+='0';
                i++;
                for(int j=i; j<sz; j++)
                {
                    binR+='1';
                }
            }
        }
        // cout<<binL<<" "<<binR<<endl;
        int ans = 0;
        if(binL.size()>binR.size())ans=0;
        else if(binL.size()==binR.size()){
            reverse(vf(binR));
            for(int j=0;j<binR.size();j++){
                if(binR[j]=='1'){
                    ans+=(1<<j);
                }
            }
            ans+=1;
            //cout<<"ans:"<<ans<<" "<<binR<<endl;
            reverse(vf(binL));
            int tmp = 0;
            int val = 0;
            for(int j=0;j<binL.size();j++){
                if(binL[j]=='1'){
                    tmp+=(1<<j);
                }
            }
            ans-=tmp;
        }
        else{
            int k = binL.size()+1;
            for(int j=k;j<binR.size();j++){
                for(int l=0;l<j;l++){
                    ans+=(1<<l);
                }
                ans++;
                //cout<<ans<<endl;
            }
           // cout<<"ans:"<<ans<<" "<<k<<endl;
            reverse(vf(binR));
            for(int j=0;j<binR.size();j++){
                if(binR[j]=='1'){
                    ans+=(1<<j);
                }
            }
            ans+=1;
            //cout<<ans<<endl;
            reverse(vf(binL));
            int tmp = 0;
            int val = 0;
            for(int j=0;j<binL.size();j++){
                if(binL[j]=='1'){
                    tmp+=(1<<j);
                }
                val+=(1<<j);
            }
            ans+=(val-tmp+1);
        }
        cout<<max(0LL,ans)<<endl;
    }
    return 0;
}

