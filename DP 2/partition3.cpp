#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool partition3(vector<int> A) {
    int n = A.size();
    int sum = accumulate(A.begin(), A.end(), 0);
    if(sum % 3 != 0) return false;
    int target = sum / 3;
    vector<vector<vector<bool>>> dp(
        n + 1,
        vector<vector<bool>>(target + 1, vector<bool>(target + 1, false))
    );

    dp[0][0][0] = true;
    for(int i = 1; i <= n; i++) {
        int x = A[i - 1];
        for(int j = 0; j <= target; j++) {
            for(int k = 0; k <= target; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if(j >= x) dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - x][k];
                if(k >= x) dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - x];
            }
        }
    }
    return dp[n][target][target];
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    cout << partition3(A) << endl;
    return 0;
}