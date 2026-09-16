#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll max_pairwise_product(vector<ll> numbers) {
    ll n = numbers.size();
    ll max1 = 0;
    ll max2 = 0;
    for(ll i = 0; i < n; i++) {
        if(numbers[i] > max1) {
            max2 = max1;
            max1 = numbers[i];
        } else if(numbers[i] > max2) max2 = numbers[i];
    }
    return max1 * max2;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> numbers(n);
    for(ll i = 0; i < n; i++) cin >> numbers[i];
    cout << max_pairwise_product(numbers) << endl;
    return 0;
}