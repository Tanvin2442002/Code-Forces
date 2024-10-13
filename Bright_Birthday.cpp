#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
//  #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
int inf = 1e18;

int freq[16][26];

vector<string> v = {"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};

int mx = 0;

int f(int i) {
             int flag = 1;
            for(int j=0;j<26;j++) {
                if(freq[0][j] < freq[i][j]) {
                    flag = 0;
                    break;
                }
            }
            int cnt = 0;
            if(flag) {
                for(int j=0;j<26;j++) {
                    freq[0][j] -= freq[i][j];
                }
                cnt = 1 + f(i-1);
                for(int j=0;j<26;j++) {
                    freq[0][j] += freq[i][j];
                }
            }
            cnt = max(cnt, f(i-1));
            mx = max(mx, cnt);
}
int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    for(int i=1;i<=15;i++) {
        for(int j=0;j<v[i-1].size();j++) {
            freq[i][v[i-1][j]-'a']++;
        }
    }
    while (t--)
    {
        string s;
        cin >> s;
        mx = 0;
        for (int j = 0; j < 26; j++)
        {
            freq[0][j] = 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            freq[0][s[i] - 'a']++;
        }

        f(15);
        cerr << '\n';
        cout << mx << endl;
    }
    return 0;
}
