#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;

void partition3(vector<int>& a, int l, int r, int& m1, int& m2) {
    int x = a[l];
    int lt = l;
    int i = l;
    int gt = r;
    while(i <= gt) {
        if(a[i] < x) {
            swap(a[i], a[lt]);
            i++;
            lt++;
        } else if(a[i] > x) {
            swap(a[i], a[gt]);
            gt--;
        } else i++;   
    }
    m1 = lt;
    m2 = gt;
}

void sorting(vector<int>& a, int l, int r) {
    if(l >= r) return;
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1, m2;
    partition3(a, l, r, m1, m2);
    sorting(a, l, m1 - 1);
    sorting(a, m2 + 1, r);
}

int main() {
    srand(time(0));
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sorting(a, 0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}