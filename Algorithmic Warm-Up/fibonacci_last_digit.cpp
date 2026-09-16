#include <iostream>
#define ll long long
using namespace std;

int fibonacci_last_digit(ll n) {
    if(n <= 1) return n;
    int a = 0, b = 1;
    for(ll i = 2; i <= n; i++) {
        int c = (a + b) % 10;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    ll n;
    cin >> n;
    cout << fibonacci_last_digit(n) << endl;
    return 0;
}