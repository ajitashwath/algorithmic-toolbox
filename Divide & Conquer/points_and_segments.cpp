#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<int> points_and_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    vector<int> ans;
    for(int x : points) {
        int left = upper_bound(starts.begin(), starts.end(), x) - starts.begin();
        int right = lower_bound(ends.begin(), ends.end(), x) - ends.begin();
        ans.push_back(left - right);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> starts(n);
    vector<int> ends(n);
    vector<int> points(m);
    for(int i = 0; i < n; i++) cin >> starts[i] >> ends[i];
    for(int i = 0; i < m; i++) cin >> points[i];
    vector<int> ans = points_and_segments(starts, ends, points);
    for(int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}