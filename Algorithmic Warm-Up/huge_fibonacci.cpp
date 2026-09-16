// Pisano Period (pie(n))
// Repeating length of Fibonacci seq when its no. are divided by given int n and expressed as remainders modulo n

// For modulo m, Fibonacci numbers repeat with a period

#include <iostream>
#define ll long long
using namespace std;

ll get_pisano_period(ll m) {
    ll prev = 0;
    ll curr = 1;
    for(ll i = 0; i < m * m; i++) {
        ll next = (prev + curr) % m;
        prev = curr;
        curr = next;
        if(prev == 0 && curr == 1) return i + 1;
    }
    return 0;
}

ll huge_fibonacci(ll n, ll m) {
    ll period = get_pisano_period(m);
    n %= period;
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

int main() {
    ll n, m;
    cin >> n >> m;
    cout << huge_fibonacci(n, m) << endl;
}