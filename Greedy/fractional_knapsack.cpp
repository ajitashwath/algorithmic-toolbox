#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;

double fractional_knapsack(int capacity, vector<int> weights, vector<int> values) {
    int n = weights.size();
    vector<pair<double, int>> items;

    for(int i = 0; i < n; i++) {
        double ratio = (double)values[i] / weights[i];
        items.push_back({ratio, i});
    }

    sort(items.rbegin(), items.rend());
    double ans = 0;
    for(auto item : items) {
        int i = item.second;
        if(capacity == 0) break;
        int take = min(capacity, weights[i]);
        ans += take * ((double)values[i] / weights[i]);
        capacity -= take;
    }
    return ans;
}

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> values(n), weights(n);
    for(int i = 0; i < n; i++) cin >> values[i] >> weights[i];
    cout << fixed << setprecision(10);
    cout << fractional_knapsack(capacity, weights, values) << endl;
    return 0;
}