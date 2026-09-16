#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

ll edit_distance(string a, string b) {
    ll n = a.size();
    ll m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for(ll i = 0; i <= n; i++) dp[i][0] = i;
    for(ll j = 0; j <= m; j++) dp[0][j] = j;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + 1
                });
            }
        }
    }
    return dp[n][m];
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << edit_distance(a, b) << endl;
    return 0;
}