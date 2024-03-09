#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int loc[n];
        for (int i = 0; i < n; i++) {
            cin >> loc[i];
        }

        int min = 0;
        int max = 0;

        for (int i = 0; i < n; i++) {
            if (loc[i] > l / 2) {
                if (l - loc[i] > min) {
                    min = l - loc[i];
                }
                if (loc[i] > max) {
                    max = loc[i];
                }
            } else {
                if (loc[i] > min) {
                    min = loc[i];
                }
                if (l - loc[i] > max) {
                    max = l - loc[i];
                }
            }
        }

        cout << min << " " << max << endl;
    }
}
