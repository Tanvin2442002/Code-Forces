#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int type[MAX], cnt[MAX];
int ar[MAX];
bool used[MAX];
pair<int, int> ans[MAX];

int main() {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    for(int i = n - 2; i >= 0; i--) {
        if(ar[i] <= ar[i + 1]) {
            type[i] = 0;
            cnt[i] = (type[i] == type[i + 1]) ? cnt[i + 1] + 1 : 1;
        } else {
            type[i] = 1;
            cnt[i] = (type[i] == type[i + 1]) ? cnt[i + 1] + 1 : 1;
        }
    }

    int q;
    scanf("%d", &q);
    while(q--) {
        int mn;
        scanf("%d", &mn);
        if(used[mn]) {
            printf("%d %d\n", ans[mn].first, ans[mn].second);
            continue;
        }

        used[mn] = 1;
        int cnt1 = 0, cnt2 = 0;
        int idx = 0;
        while(idx < n) {
            int nxt = cnt[idx];
            cnt1++;
            if(nxt >= mn - 1) idx += cnt[idx] + 1;
            else {
                cnt2 += (min(mn, n - idx) - cnt[idx] - 1);
                idx += mn;
            }
        }
        ans[mn] = {cnt1, cnt2};
        printf("%d %d\n", ans[mn].first, ans[mn].second);
    }

    return 0;
}
