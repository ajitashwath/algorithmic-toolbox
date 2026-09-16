#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int car_fueling(int dist, int tank, vector<int> stops) {
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);

    int cnt = 0, current = 0;
    while(current < stops.size() - 1) {
        int last = current;
        while(current < stops.size() - 1 && stops[current + 1] - stops[last] <= tank) current++;
        if(current == last) return -1;
        if(current < stops.size() - 1) cnt++;
    }
    return cnt;
}

int main() {
    int dist, tank, n;
    cin >> dist >> tank >> n;
    vector<int> stops(n);
    for(int i = 0; i < n; i++) cin >> stops[i];
    cout << car_fueling(dist, tank, stops) << endl;
    return 0;
}