#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum += num;
    }

    cout << -sum;
}
