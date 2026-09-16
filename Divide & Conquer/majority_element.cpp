#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int get_majority(vector<int>& a, int l, int r) {
    if(l == r) return a[l];
    int m = l + (r - l) / 2;
    int left = get_majority(a, l, m);
    int right = get_majority(a, m + 1, r);
    
    if(left == right) return left;
    int left_count = 0, right_count = 0;

    for(int i = l; i <= r; i++) {
        if(a[i] == left) left_count++;
        if(a[i] == right) right_count++;
    }
    if(left_count > (r - l + 1) / 2) return left;
    if(right_count > (r - l + 1) / 2) return right;
    return -1;
}

int majority_element(vector<int> a) {
    int n = a.size();
    if(n == 0) return 0;
    return get_majority(a, 0, n - 1) != -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << majority_element(a) << endl;
    return 0;
}