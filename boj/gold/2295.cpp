#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> u(n);
    vector<long long> two;

    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }

    sort(u.begin(), u.end());


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            two.push_back(u[i] + u[j]);
        }
    }

    sort(two.begin(), two.end());

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(two.begin(), two.end(), u[i] - u[j])) {
                cout << u[i];
                return 0;
            }
        }
    }
}
