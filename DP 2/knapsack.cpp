#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll optimal_weight(ll W, vector<ll> weights) {
    ll n = weights.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll w = 1; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if(weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    dp[i - 1][w - weights[i - 1]] + weights[i - 1]
                );
            }
        }
    }
    return dp[n][W];
}

int main() {
    ll W, n;
    cin >> W >> n;
    vector<ll> weights(n);
    for(ll i = 0; i < n; i++) cin >> weights[i];
    cout << optimal_weight(W, weights) << endl;
    return 0;
}