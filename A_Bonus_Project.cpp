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
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
int inf  = 1e18;

class sw{
 public: 
  int n;
  int ai;
  int bi;
  float eff;
};

bool compare(sw a , sw b){
  return a.eff > b.eff;
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    //cin >> t;
    while(t--){
      int n,k;
      cin >> n >>k;
      vector<sw>persons(n);
      vector<int>res(n,0);
      for(int i=0;i<n;i++){
        cin >> persons[i].ai;
        persons[i].n = i;
      }
      for(int i = 0;i<n;i++){
        cin >> persons[i].bi;
        float e =  persons[i].ai*persons[i].bi;
        persons[i].eff = e;
      }
      sort(persons.begin(),persons.end(),compare);
      int rem = k;
      for(auto i:persons){
        if(rem<=0)break;
        int mx = i.ai/i.bi;
        int  w = min(mx,rem);
        res[i.n]= w;
        rem-=w;
      } 
      if(rem>0){
        for(int i=0;i<n;i++){
          res[i]=0;
        }
      }
      for(auto i:res){
        cout<<i<<" ";
      }
      cout<<endl;
    }
    return 0;
}


