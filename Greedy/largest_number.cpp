#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largest_number(vector<string> numbers) {
    sort(numbers.begin(), numbers.end(),
         [](const string& a, const string& b) {
             return a + b > b + a;
         });
    string res;
    for(const string& number : numbers) res += number;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for(auto& number : numbers) cin >> number;
    cout << largest_number(numbers) << endl;
    return 0;
}