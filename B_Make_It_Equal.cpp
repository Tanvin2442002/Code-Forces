#include <iostream>
#include <vector>
using namespace std;

long long solveTestCase(int n, vector<int>& a) {
    long long sum = 0;
    for (int x : a) sum += x;

    if (sum % n != 0) return -1; // Impossible case
    int target = sum / n;

    long long operations = 0, carry = 0;
    for (int i = 0; i < n; i++) {
        // Calculate excess or deficit at the current index
        carry += a[i] - target;
        operations += abs(carry); // Track the operations required
    }

    return operations;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solveTestCase(n, a) << "\n";
    }
    return 0;
}
