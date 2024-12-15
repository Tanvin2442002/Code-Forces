#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>v(n);
        vector<int>mergeornot(n,0);
        int sum1 = 0;
        for(int i = 0; i<n; i++)
        {
            cin >> v[i];
            sum1 += v[i] * (i + 1);
            dbg(v[i] * (i + 1));
        }
        dbg(sum1);
        vector<int>suffix(n);
        suffix[n-1]=v[n-1];
        for(int i=n-1; i>0; i--)
        {
            suffix[i-1]=suffix[i]+v[i-1];
        }
        // reverse(suffix.begin(),suffix.end());
        for(int i = 0;i<n;i++){
          if(suffix[i]<0){
            if(i>0){
              mergeornot[i-1]=2;
            }
            while(suffix[i]<0 and i<n){
              mergeornot[i]=1;
              i++;
            }
            i--;
          }

        }
        dbg(suffix);
        dbg(mergeornot);  
        int cnt = 1;
        int sum = 0;
        int mx = 0;
        int s = 0;
        for(int i=0; i<n; i++)
        {
            if(mergeornot[i])
            {   sum = 0;
                while(mergeornot[i]>0 and i<n)
                {
                    sum+=v[i];
                    i++;
                    if(mergeornot[i]==2){
                      break;
                    }
                }
                mx = (cnt*sum);
                cnt++;
                i--;
            }
            else
            {
                mx = v[i]*cnt;
                cnt++;
            }
            dbg(mx);
            s+=mx;
        }
        cout<<s<<endl;
    }
}
