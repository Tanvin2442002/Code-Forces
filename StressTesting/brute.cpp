#include<bits/stdc++.h>
using namespace std;
#define sz 200005
#define vec array<int,3>
#define pa pair<int,int>
#define ll long long int
string cd = "codeforces";
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_case = 1;
    cin >> test_case;
    for(int cs = 1;cs<=test_case;cs++) {
    	std::vector<int> v(26),v1(26);
    	string c;
    	int n;
    	cin >> n >> c;
    	for(char cc:c)
    		v[cc-'a']++;
    	int ans = 0;
    	for(int i = 0;i+1<n;i++) {
    		int a = c[i] - 'a';
    		v[a]--;
    		v1[a]++;
    		int asd = 0;
    		for(int j = 0;j<26;j++) {
    			asd += (v[j] > 0) + (v1[j] > 0);
    		}
    		ans = max(ans,asd);
    	}
    	cout << ans <<"\n";
    }
}