#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define ll long long
using namespace std;

struct Point {
    long long x;
    long long y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double brute_force(vector<Point>& p, int l, int r) {
    double ans = 1e18;
    for(int i = l; i <= r; i++) {
        for(int j = i + 1; j <= r; j++) ans = min(ans, distance(p[i], p[j]));
        
    }
    return ans;
}

double closest_pair(vector<Point>& p, int l, int r) {
    if(r - l <= 2) return brute_force(p, l, r);

    int m = l + (r - l) / 2;
    double left = closest_pair(p, l, m);
    double right = closest_pair(p, m + 1, r);
    double d = min(left, right);

    vector<Point> strip;
    for(int i = l; i <= r; i++) {
        if(abs(p[i].x - p[m].x) < d) strip.push_back(p[i]);
    }

    sort(strip.begin(), strip.end(), [](Point a, Point b) {
        return a.y < b.y;
    });

    for(int i = 0; i < strip.size(); i++) {
        for(int j = i + 1;
            j < strip.size() && strip[j].y - strip[i].y < d;
            j++) {
            d = min(d, distance(strip[i], strip[j]));
        }
    }
    return d;
}

double closest(vector<Point> points) {
    if(points.size() < 2) return 0;
    sort(points.begin(), points.end(), [](Point a, Point b) {
        return a.x < b.x;
    });
    return closest_pair(points, 0, points.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
    cout << fixed << setprecision(9);
    cout << closest(points) << endl;
    return 0;
}