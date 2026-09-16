#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> optimal_sequence(ll n) {
    vector<ll> dp(n + 1);
    vector<ll> parent(n + 1);
    dp[1] = 0;

    for(ll i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        parent[i] = i - 1;
        if(i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            parent[i] = i / 2;
        }
        if(i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            parent[i] = i / 3;
        }
    }

    vector<ll> sequence;
    while(n >= 1) {
        sequence.push_back(n);
        if(n == 1) break;
        n = parent[n];
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << endl;
    for(ll x : sequence) cout << x << " ";
    cout << endl;
    return 0;
}