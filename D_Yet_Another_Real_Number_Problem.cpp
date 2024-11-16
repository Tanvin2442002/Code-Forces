#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>
using ll = long long;

int mod = 1000000007;
int inf = 1e18;

ll power(ll base, ll n, ll m = mod) {
  if (n == 0)
    return 1;
  if (n & 1) {
    ll x = power(base, n / 2);
    return ((x * x) % m * base) % m;
  } else {
    ll x = power(base, n / 2);
    return (x * x) % m;
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
    cin >> v[i];

  auto divisible_by_2 = [](ll num) {
    ll cnt = 0, x = num;
    while (num % 2 == 0) {
      cnt++;
      num /= 2;
    }
    return make_pair(cnt, x - num);
  };

  stack<pair<ll, pair<ll, ll>>> st;
  vector<ll> finalAns(n);
  finalAns[0] = v.front();
  auto cnt_two = divisible_by_2(v.front());
  if (cnt_two.first > 0) {
    st.push({v.front(), cnt_two});
  }

  auto stack_cal = [](stack<pair<ll, pair<ll, ll>>> stk) {
    ll cnt_of_two = 0, reduce = 0;
    while (stk.size()) {
      auto top = stk.top();
      cnt_of_two += top.second.first;
      reduce += top.second.second;
      stk.pop();
    }
    return make_pair(cnt_of_two, reduce);
  };

  auto stack_print = [](stack<pair<ll, pair<ll, ll>>> stk) {
    while (stk.size()) {
      dbg(stk.top());
      stk.pop();
    }
    return;
  };

  for (ll i = 1; i < n; i++) {
    ll possible_ans1 = (finalAns[i - 1] + v[i]) % mod;
    auto cal = stack_cal(st);
    ll cnt_of_two = cal.first, reduce = cal.second;

    ll val = (v[i] * power(2, cnt_of_two)) % mod;
    ll possible_ans2 = (finalAns[i - 1] + val - reduce) % mod;
    ll f = 0;
    dbg("--------", i);
    stack_print(st);
    dbg(possible_ans1);
    dbg(possible_ans2);
    dbg(val);
    dbg(cnt_of_two, reduce);
    while (possible_ans2 >= possible_ans1 and !st.empty()) {
      st.pop();
      f = 1;
    }
    finalAns[i] = (f == 1 ? possible_ans2 : possible_ans1);
    auto new_divisible = divisible_by_2((f == 1 ? val : v[i]));
    dbg(val, new_divisible);
    st.push({val, new_divisible});
  }
  for (auto i : finalAns)
    cout << i << " ";
  cout << '\n';
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}