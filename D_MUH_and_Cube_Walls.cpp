#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else 
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int   long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

vector<int>prefix_function(vector<int>&pat){
   int n = pat.size();
   int i=1;
   vector<int>pi(n);
   int j = 0;
   pi[0]=0;
   while(i<n){
     if(pat[i]==pat[j]){
        j++;
        pi[i]=j;
        i++;
     }
     else{
       if(j==0){
         pi[i]=0;
         i++;
       }
       else{
         j=pi[j-1];
       }
     }
   }
   return pi;
}


int32_t main()
{
    fastio;in;out;
    int t = 1;
    // cin >> t;
    while(t--){
      int n,w;
      cin >> n >> w;
      vector<int>bear(n),elephant(w);
      for(int i=0;i<n;i++){
        cin >> bear[i];
      }
      for(int i=0;i<w;i++){
        cin >> elephant[i];
      }
      if(w==1){
        cout << n << endl;
        continue;
      }
      vector<int>beardiff(n-1),elephantdiff(w-1);
      for(int i=0;i<n-1;i++){
        beardiff[i] = bear[i+1]-bear[i];
      }
      for(int i=0;i<w-1;i++){
        elephantdiff[i] = elephant[i+1]-elephant[i];
      }
      // dbg(beardiff);
      // dbg(elephantdiff);
      vector<int>lps=prefix_function(elephantdiff);
      // dbg(lps);
      int i = 0 , j = 0;
      int cnt = 0;
      while(i<n-1){
        if(beardiff[i]==elephantdiff[j]){
          i++;
          j++;
          if(j==w-1){
            cnt++;
            j = lps[j-1];
          }
        }
        else {
          if(j==0)i++;
          else{
            j = lps[j-1];
          }
        }
      }
      cout << cnt << endl;
    }
    return 0;
}