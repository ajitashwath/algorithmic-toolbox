#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll lcs3(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
    ll n = a.size();
    ll m = b.size();
    ll k = c.size();

    vector<vector<vector<ll>>> dp(
        n + 1,
        vector<vector<ll>>(
            m + 1,
            vector<ll>(k + 1, 0)
        )
    );

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            for(ll x = 1; x <= k; x++) {

                if(a[i - 1] == b[j - 1] && b[j - 1] == c[x - 1]) {
                    dp[i][j][x] = dp[i - 1][j - 1][x - 1] + 1;
                }
                else {
                    dp[i][j][x] = max({
                        dp[i - 1][j][x],
                        dp[i][j - 1][x],
                        dp[i][j][x - 1]
                    });
                }
            }
        }
    }

    return dp[n][m][k];
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);

    for(ll i = 0; i < n; i++)
        cin >> a[i];

    ll m;
    cin >> m;

    vector<ll> b(m);

    for(ll i = 0; i < m; i++)
        cin >> b[i];

    ll k;
    cin >> k;

    vector<ll> c(k);

    for(ll i = 0; i < k; i++)
        cin >> c[i];

    cout << lcs3(a, b, c) << endl;

    return 0;
}