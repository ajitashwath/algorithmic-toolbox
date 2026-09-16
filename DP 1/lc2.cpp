#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll lcs2(vector<ll> &a, vector<ll> &b) {
    ll n = a.size();
    ll m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {

            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
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

    cout << lcs2(a, b) << endl;

    return 0;
}