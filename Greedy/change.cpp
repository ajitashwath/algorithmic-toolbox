#include <iostream>
#include <vector>
#define ll long long 
using namespace std;

int change(int m) {
    vector<int> coins = {10, 5, 1};
    int cnt = 0;
    for(int i : coins) {
        cnt += m / i;
        m %= i;
    }
    return cnt;
}

int main() {
    int m;
    cin >> m;
    cout << change(m) << endl;
    return 0;
}