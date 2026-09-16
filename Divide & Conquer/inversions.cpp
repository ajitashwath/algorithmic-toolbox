#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll merge_sort(vector<int>& a, vector<int>& temp, int l, int r) {
    if(l >= r) return 0;
    int m = l + (r - l) / 2;
    ll ans = 0;
    ans += merge_sort(a, temp, l, m);
    ans += merge_sort(a, temp, m + 1, r);
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while(i <= m) temp[k++] = a[i++];
    while(j <= r) temp[k++] = a[j++];
    for(i = l; i <= r; i++) a[i] = temp[i];
    return ans;
}

ll inversions(vector<int> a) {
    vector<int> temp(a.size());
    if(a.empty()) return 0;
    return merge_sort(a, temp, 0, a.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << inversions(a) << endl;
    return 0;
}