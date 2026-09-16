#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int binary_search(vector<int> a, int x) {
    int l = 0;
    int r = a.size() - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(a[m] == x) return m;
        if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << binary_search(a, x) << " ";
    }
    cout << endl;
    return 0;
}