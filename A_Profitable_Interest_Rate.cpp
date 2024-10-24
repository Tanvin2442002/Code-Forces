#include<bits/stdc++.h>
using namespace std;

void minimum_button_presses(int t) {
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);

        long long total_cans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_cans += a[i];
        }

        // First round: Press all n buttons once
        long long first_round_cans = min(n, total_cans);

        // Calculate remaining cans to collect
        long long remaining_cans = max(0LL, k - first_round_cans);

        // Total presses: n (first round) + remaining presses
        long long total_presses = n + remaining_cans;

        cout << total_presses << endl;
    }
}

int main() {
    int t;
    cin >> t;
    minimum_button_presses(t);
    return 0;
}