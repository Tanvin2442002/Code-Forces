#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-7;

// Circle and ellipse parameters
double x_c, y_c, r, h, k, a, b;

// Distance function
double distance(double theta, double phi) {
    // Point on the circle
    double cx = x_c + r * cos(theta);
    double cy = y_c + r * sin(theta);
    // Point on the ellipse
    double ex = h + a * cos(phi);
    double ey = k + b * sin(phi);
    // Euclidean distance
    return sqrt((cx - ex) * (cx - ex) + (cy - ey) * (cy - ey));
}

// Ternary search over phi
double ternarySearchPhi(double theta) {
    double left = 0, right = 2 * PI;
    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        if (distance(theta, mid1) < distance(theta, mid2))
            right = mid2;
        else
            left = mid1;
    }
    return distance(theta, left);
}

// Ternary search over theta
double ternarySearchTheta() {
    double left = 0, right = 2 * PI;
    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        if (ternarySearchPhi(mid1) < ternarySearchPhi(mid2))
            right = mid2;
        else
            left = mid1;
    }
    return ternarySearchPhi(left);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        // Input circle and ellipse parameters
        cin >> x_c >> y_c >> r;
        cin >> h >> k >> a >> b;

        // Check overlap
        double centerDist = sqrt((x_c - h) * (x_c - h) + (y_c - k) * (y_c - k));
        if (centerDist <= r + a) {
            cout << fixed << setprecision(6) << 0.0 << endl;
        } else {
            // Compute minimum distance using ternary search
            double minDist = ternarySearchTheta();
            cout << fixed << setprecision(6) << minDist << endl;
        }
    }
    return 0;
}
