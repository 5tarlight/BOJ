#include <iostream>

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
        int max = -1e9;
        int min = 1e9;
        while (n--) {
            int a;
            cin >> a;
            if (a > max) {
                max = a;
            }
            if (a < min) {
                min = a;
            }
        }

        cout << min << ' ' << max << '\n';
    }
}
