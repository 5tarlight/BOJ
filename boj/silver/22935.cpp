#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n--;

        // 1 ~ 15 ~ 1 -> 29

        int target = n % 28;
        if (target > 14) {
            target = 28 - target;
        }

        target++;
        for (int i = 3; i >= 0; i--) {
            if (target & 1 << i) {
                cout << "딸기";
            } else {
                cout << "V";
            }
        }

        cout << '\n';
    }
}
