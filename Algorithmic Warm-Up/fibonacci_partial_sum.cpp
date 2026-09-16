#include <iostream>
#define ll long long
using namespace std;

ll fibonacci_mod(ll n, ll m) {
    if(n <= 1) return n % m;
    ll prev = 0;
    ll curr = 0;
    for(ll i = 2; i <= n; i++) {
        ll next = (prev + curr) % m;
        prev = curr;
        curr = next;
    }
    return curr;
}

ll fibonacci_sum(ll n) {
    if(n < 0) return 0;
    n %= 60;
    ll res = fibonacci_mod(n + 2, 10);
    return (res + 9) % 10;
}

ll fibonacci_partial_sum(ll from, ll to) {
    ll res = (fibonacci_sum(to) - fibonacci_sum(from - 1) + 10) % 10;
    return res;
}

int main() {
    ll from, to;
    cin >> from >> to;
    cout << fibonacci_partial_sum(from, to) << endl;
    return 0;
}

