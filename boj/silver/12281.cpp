#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        int n;
        cin >> n;
        int a[n];
        vector<int> odd, even;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }

        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end());

        cout << "Case #" << c + 1 << ": ";
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                cout << even.back() << " ";
                even.pop_back();
            } else {
                cout << odd.back() << " ";
                odd.pop_back();
            }
        }
        cout << '\n';
    }
}
