#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define pll pair<ll, ll>
#define nl "\n"
#define printa(a, L, R)for (int i = L; i < R; i++) cout << a[i] << (i == R - 1 ? '\n' : ' ')
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define F first
#define S second
#define mem(a, x) memset(a, x, sizeof(a))
const ll infi = 1e18;
const ll mod = 1e9 + 7;
const ll N = 1e5 + 3;
float pi = acos(-1);
void __print(ll x){cerr << x;}
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x){cerr << '{';__print(x.first);cerr << ',';__print(x.second);cerr << '}';}
template <typename T>
void __print(const T &x){ll f = 0;cerr << '{';for (auto &i : x)cerr << (f++ ? "," : ""),__print(i);cerr << "}";}
void _print() { cerr << ""; }
template <typename T, typename... V>
void _print(T t, V... v){__print(t);if (sizeof...(v))cerr << ", ";_print(v...);}
void _print(ll t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(float t) { cerr << t; }
void _print(string t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T>
void _print(vector<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << " ]";}
template <class T>
void _print(set<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << " ]";}
template <class T>
void _print(multiset<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << " ]";}
template <class T, class V>
void _print(map<T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << " ]";}
#define debug(x...)cerr << "[ " << #x << " ] = [";  _print(x);cerr << " ]" << endl;
ll cs;
#define _case cout << "Case " << ++cs << ": "
#define rev(v) reverse(v.begin(), v.end())
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define dosomic(x) fixed << setprecision(x)
bool isPowerOfTwo(ll n){ return (n && !(n & (n - 1))); }
string to_binary(ll n) { return bitset<4>(n).to_string();}
ld b, c;
ld func(ld x){
  ld y=(x*x+b*x+c)/(ld)sin(x);
  return y;
}
void solve()
{
  cin>>b>>c;
  ld l=0,h=(ld)pi/2.0,eps=1e-10;
  while(h-l>eps){
    ld m1=l+(h-l)/3;
    ld m2=h-(h-l)/3;
    if(func(m1)<func(m2)){
      h=m2;
    }else
    {
      l=m1;
    }
  }
  cout<<fixed<<setprecision(10)<<func(l)<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}