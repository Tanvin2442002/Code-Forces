#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;

int mx(vector<int>& a) {
    if(a.size()==1)return a[0];
    while (a.size() > 1) {
        int n = a.size();
        vector<int> diffSeq;
        for (int i = 1; i < n; i++) {
            diffSeq.push_back(a[i] - a[i - 1]);
        }
        reverse(vf(diffSeq));
        a = diffSeq;
    }
    return a[0];
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin >> v[i];
      }
      vector<int>copy = v;
      reverse(vf(copy));
      int s = accumulate(vf(v),0);
      cout << max(s,mx(v)) << endl;
    }
    return 0;
}