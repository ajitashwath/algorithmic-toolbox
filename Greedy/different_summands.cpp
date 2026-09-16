#include <iostream>
#include <vector>
using namespace std;

vector<int> different_summands(int n) {
    vector<int> summands;
    int next = 1;
    while(n >= next) {
        summands.push_back(next);
        n -= next;
        next++;
    }
    if(n > 0) summands.back() += n;
    return summands;
}

int main() {
    int n;
    cin >> n;
    vector<int> summands = different_summands(n);
    cout << summands.size() << endl;
    for(int x : summands) cout << x << ' ';
    cout << endl;
    return 0;
}