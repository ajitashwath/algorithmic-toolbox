#include <iostream>
#define ll long long
using namespace std;

ll fibonacci(int n) {
    if(n <= 1) return n;
    ll a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        ll c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}