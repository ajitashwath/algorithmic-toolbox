#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll dot_product(vector<ll> a, vector<ll> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for(int i = 0; i < a.size(); i++) ans += a[i] * b[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    cout << dot_product(a, b) << endl;
    return 0;
}