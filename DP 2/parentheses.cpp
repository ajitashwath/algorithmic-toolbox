#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

long long eval(long long a, long long b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

long long get_maximum_value(string exp) {
    int n = (exp.size() + 1) / 2;

    vector<long long> numbers(n);
    vector<char> operators(n - 1);

    for(int i = 0; i < n; i++)
        numbers[i] = exp[2 * i] - '0';

    for(int i = 0; i < n - 1; i++)
        operators[i] = exp[2 * i + 1];

    vector<vector<long long>> mn(n, vector<long long>(n));
    vector<vector<long long>> mx(n, vector<long long>(n));

    for(int i = 0; i < n; i++)
        mn[i][i] = mx[i][i] = numbers[i];

    for(int s = 1; s < n; s++) {
        for(int i = 0; i < n - s; i++) {
            int j = i + s;

            mn[i][j] = LLONG_MAX;
            mx[i][j] = LLONG_MIN;

            for(int k = i; k < j; k++) {
                long long a = eval(mx[i][k], mx[k + 1][j], operators[k]);
                long long b = eval(mx[i][k], mn[k + 1][j], operators[k]);
                long long c = eval(mn[i][k], mx[k + 1][j], operators[k]);
                long long d = eval(mn[i][k], mn[k + 1][j], operators[k]);

                mx[i][j] = max({mx[i][j], a, b, c, d});
                mn[i][j] = min({mn[i][j], a, b, c, d});
            }
        }
    }

    return mx[0][n - 1];
}

int main() {
    string exp;
    cin >> exp;

    cout << get_maximum_value(exp) << endl;
    return 0;
}