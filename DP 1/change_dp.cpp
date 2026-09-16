#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll get_change(ll m) {
    vector<ll> dp(m + 1, m + 1);
    dp[0] = 0;
    for(ll i = 1; i <= m; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);
        if(i >= 4) dp[i] = min(dp[i], dp[i - 4] + 1);
    }
    return dp[m];
}

int main() {
    ll m;
    cin >> m;
    cout << get_change(m) << endl;
    return 0;
}