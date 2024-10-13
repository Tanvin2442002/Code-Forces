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

bool check(deque<int> dq)
{
    int n = dq.size();
    cout << "?" << " ";
    for (int i = 0; i < n; i++)
    {
        cout << dq[i];
    }
    cout << endl;
    bool res;
    cin >> res;
    return res;
}

int32_t main() // 000011
{              // 11010  //11100111100
    // fastio;in;out;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        deque<int> dq;
        if (n > 2)
        {
            dq.push_back(0);
            dq.push_back(0);
            for (int i = 0; i < 2 * n; i++) // 0 1 2 3 4 5
            {
                if (check(dq))
                {
                    dq.push_back(0);
                }
                else
                {
                    if (dq.back() == 0)
                    {
                        dq.pop_back();
                        dq.push_back(1);
                    }
                    else
                    {
                        dq.pop_back();
                        break;
                    }
                }
                if (dq.size() == n + 1)
                {
                    dq.pop_back();
                    break;
                }
            }
            if (dq.size() < n)
            {
                dq.push_front(0);
                if (!check(dq))
                {
                    dq.pop_front();
                    dq.push_front(1);
                    if (!check(dq))
                    {
                        cout << "! ";
                        for (int i = 0; i < n; i++)
                        {
                            cout << 1;
                        }
                        cout << endl;
                        continue;
                    }
                    else
                    {
                       if(dq.size() == n)
                       {
                           cout << "! ";
                           for (int i = 0; i < n; i++)
                           {
                               cout << dq[i];
                           }
                           cout << endl;
                           continue;
                       }
                       else
                       {
                           dq.push_front(0);
                       }
                    }
                }
                for (int i = 0; i < 2 * n - 2; i++) // 1101110
                {
                    if (check(dq))
                    {
                        dq.push_front(0);
                    }
                    else
                    {
                        dq.pop_front();
                        dq.push_front(1);
                    }
                    if (dq.size() == n + 1)
                    {
                        dq.pop_front();
                        break;
                    }
                }
            }
            cout << "! ";
            for (int i = 0; i < n; i++)
            {
                cout << dq[i];
            }
            cout << endl;
            continue;
        }
        else if (n == 2)
        {
            dq.push_back(0);
            if (check(dq)) // 1 0
            {
                dq.push_back(0);
            }
            else
            {
                cout << "! 11" << endl;
                continue;
            }

            if (check(dq))
            {
                cout << "! ";
                cout << dq[0] << dq[1] << endl;
                continue;
            }
            else
            {
                dq.pop_back();
                dq.push_back(1);
            }
            if (check(dq))
            {
                cout << "! ";
                cout << dq[0] << dq[1] << endl;
            }
            else
            {
                cout << "! ";
                cout << dq[1] << dq[0] << endl;
            }
        }
        else
        {
            dq.push_back(0);
            if (check(dq))
            {
                cout << "! 0" << endl;
            }
            else
            {
                cout << "! 1" << endl;
            }
        }
    }
    return 0;
}
