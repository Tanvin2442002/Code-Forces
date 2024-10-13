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

string base = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<char, vector<string>> mp;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mp[s[0]].push_back(s);
        }
        for (auto &i : mp)
        {
            sort(i.second.begin(), i.second.end(), [&](string a, string b)
                 {
                for(int i=0;i<min(a.size(), b.size());i++){
                int x = base.find(a[i]);
                int y = base.find(b[i]);
                if(x!=y){
                    return x<y;
                }
            } 
            return a < b;
            });
            reverse(i.second.begin(), i.second.end());
        }
        int q;
        cin >> q;
        while (q--)
        {
            string a, b, c;
            cin >> a >> b >> c;
            if (mp[a[0]].empty())
            {
                cout << "Already Mastered\n";
            }
            else
            {
                cout << mp[a[0]].back() << endl;
                mp[a[0]].pop_back();
            }
        }
    }
    return 0;
}