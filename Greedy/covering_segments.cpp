#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct Segment {
    int start;
    int end;
};

vector<int> covering_segments(vector<Segment> segments) {
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {
        return a.end < b.end;
    });
    vector<int> points;
    while(!segments.empty()) {
        int point = segments[0].end;
        points.push_back(point);
        vector<Segment> temp;

        for(int i = 1; i < segments.size(); i++) {
            if(segments[i].start > point) temp.push_back(segments[i]);
        }
        segments = temp;
    }
    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for(int i = 0; i < n; i++) cin >> segments[i].start >> segments[i].end;
    vector<int> points = covering_segments(segments);
    cout << points.size() << endl;
    for(int i : points) cout << i << " ";
    cout << endl;
    return 0;
}