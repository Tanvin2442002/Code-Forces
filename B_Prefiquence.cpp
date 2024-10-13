#include <iostream>
#include <vector>
using namespace std;

vector<int> calculate_a(vector<int>& x) {
    int n = x.size() + 1;
    vector<int> a(n);

    a[0] = 1; // Set a1 to any value, here we choose 1

    for (int i = 1; i < n; ++i) {
        a[i] = x[i - 1] + a[i - 1];
    }

    return a;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> x[i];
        }

        vector<int> a = calculate_a(x);

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
