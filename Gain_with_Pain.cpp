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
        cin >> n;
        int k = n;
        int cnt = 0;
        while(n--)
        {
            for(int i=0;i<5;i++)
            {   
               int M,Q,R;
                cin >> M >> Q >> R;
                if(i==0)
                {
                    if(M==2 and Q==3 and R==10)
                    {
                        cnt++;
                    }
                }
                if(i==1)
                {
                    if(M==2 and Q==3 and R==10)
                    {
                        cnt++;
                    }
                }
                if(i==2)
                {
                    if(M==2 and Q==3 and R==10)
                    {
                        cnt++;
                    }
                }
                if(i==3)
                {
                    if(M==1 and Q==3 and R==10)
                    {
                        cnt++;
                    }
                }
                if(i==4)
                {
                    if(M==3 and Q==3 and R==10)
                    {
                        cnt++;
                    }
                }
            }
        }
        if(k*5==cnt)
        {
            cout<<"Consistent"<<endl;
        }
        else
        {
            cout<<"Inconsistent"<<endl;
        }
    }
    return 0;
}