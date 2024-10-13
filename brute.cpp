#include <bits/stdc++.h>
using namespace std;
#ifdef ONPC
#include "mydebug.h"
#else
#define debug(...) 1
#endif

void solve(){
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i=0;i<n;i++) {
        cin >> a[i];
   }
   int i = 0, j = 1, shI = 1, mx = 0;
   while(j < n) {
        j = i + 1;
        if(shI) {
            shI ^= 1;
            while(j < n && a[j] >= a[j-1]) j++;
        }
        int x = abs(a[i] - a[j-1]);
        i = j - 1;
        if(!shI) {
            shI ^= 1;
            while(j < n && a[j] <= a[j-1]) j++;
        }
        int y = abs(a[i] - a[j-1]);
        mx = max(mx, min(x, y));
        i = j - 1;
   }
   cout << mx << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests = 1;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		solve();
	}
}