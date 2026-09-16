#include <iostream>
#define ll long long
using namespace std;

ll fibonacci_mod(ll n, ll m) {
    if(n <= 1) return n % m;
    ll prev = 0;
    ll curr = 1;
    for(ll i = 2; i <= n; i++) {
        ll next = (prev + curr) % m;
        prev = curr;
        curr = next;
    }
    return curr;
}

ll fibonacci_sum_of_squares(long long n) {
    // Pisano period modulo 10 = 60
    n %= 60;
    ll fn = fibonacci_mod(n, 10);
    ll fn1 = fibonacci_mod(n + 1, 10);
    return (fn * fn1) % 10;
}

int main() {
    ll n;
    cin >> n;
    cout << fibonacci_sum_of_squares(n) << endl;
    return 0;
}