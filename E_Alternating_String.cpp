#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "F:\debug.hpp"
#else
#define dbg(x...)
#define dbgc(x...)
#endif

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
        string s;
        cin >> s;
        if (n % 2 == 0)
        {
            vector<int> odd, even;
            unordered_map<char, int> freqOdd, freqEven;
            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    even.push_back(s[i]);
                    freqEven[s[i]]++;
                }
                else
                {
                    odd.push_back(s[i]);
                    freqOdd[s[i]]++;
                }
            }
            // dbg(freqEven, freqOdd);
            int mx = 0;
            int ans = 0;
            for (auto x : freqEven)
            {
                mx = max(mx, x.second);
            }
            ans += even.size() - mx;
            mx = 0;
            for (auto x : freqOdd)
            {
                mx = max(mx, x.second);
            }
            ans += odd.size() - mx;
            cout << ans << endl;
        }
        else
        {
            int ans = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                string temp = s;
                temp.erase(temp.begin() + i);
                vector<int> odd1, even1;
                unordered_map<char, int> freqOdd1, freqEven1;
                for (int i = 0; i < n - 1; i++)
                {
                    if (i % 2 == 0)
                    {
                        even1.push_back(temp[i]);
                        freqEven1[temp[i]]++;
                    }
                    else
                    {
                        odd1.push_back(temp[i]);
                        freqOdd1[temp[i]]++;
                    }
                }
                int mx = 0;
                int tempAns = 1;
                for (auto x : freqEven1)
                {
                    mx = max(mx, x.second);
                }
                tempAns += even1.size() - mx;
                mx = 0;
                for (auto x : freqOdd1)
                {
                    mx = max(mx, x.second);
                }
                tempAns += odd1.size() - mx;
                ans = min(ans, tempAns);
            }
            cout << ans << endl;
        }
    }
    return 0;
}