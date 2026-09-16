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

ll fibonacci_sum(ll n) {
    n %= 60;
    ll res = fibonacci_mod(n + 2, 10);
    return (res + 9) % 10;
}

int main() {
    ll n;
    cin >> n;
    cout << fibonacci_sum(n) << endl;
    return 0;
}