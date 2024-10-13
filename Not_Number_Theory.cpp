
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

void find(string &s, int idx, int &maxNum, int &maxSetBits)
{
    if (idx == s.size())
    {
        int num = stoll(s);
        int setBits = __builtin_popcountll(num);
        if (setBits > maxSetBits or (setBits == maxSetBits and num > maxNum))
        {
            maxSetBits = setBits;
            maxNum = num;
        }
        return;
    }
    if (s[idx] == '?')
    {
        for (char d = '0'; d <= '9'; d++)
        {
            s[idx] = d;
            find(s, idx + 1, maxNum, maxSetBits);
            s[idx] = '?';
        }
    }
    else
    {
        find(s, idx + 1, maxNum, maxSetBits);
    }
}
int32_t main()
{
    fastio;
    in;
    out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int maxNum = -1;
        int maxSetBits = -1;
        find(s, 0, maxNum, maxSetBits);
        cout << maxNum << endl;
    }
    return 0;
}
