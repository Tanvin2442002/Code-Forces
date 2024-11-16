#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

const int MOD = 1000000007;
map<LL, int> ile;

int pow(int a, LL n) {
    if (n == 0) {
        return 1;
    }
    int r = pow(a, n / 2);
    r = (LL)r * r % MOD;
    if (n % 2 == 1) {
        r = (LL)r * a % MOD;
    }
    return r;
}

int main(void) {
    int n, x; scanf("%d%d", &n, &x);
    LL s = 0;
    VI a(n);
    REP (i, n) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    REP (i, n) {
        ++ile[s - a[i]];
    }
    while (1) {
        LL v = ile.begin()->first;
        int cnt = ile.begin()->second;
        if (cnt % x == 0) {
            ile[v + 1] += cnt / x;
            ile.erase(ile.begin());
        } else {
            printf("%d\n", pow(x, min(v, s)));
            break;
        }
    }
    return 0;
}

