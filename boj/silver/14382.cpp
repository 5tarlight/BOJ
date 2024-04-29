#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        int n;
        cin >> n;
        int found = 0;

        for (int i = 1; i <= 1000; i++) {
            int temp = i * n;
            while (temp) {
                found |= 1 << (temp % 10);
                temp /= 10;
            }

            if (found == 1023) {
                cout << "Case #" << j << ": " << i * n << "\n";
                break;
            }
        }

        if (found != 1023) {
            cout << "Case #" << j << ": INSOMNIA\n";
        }
    }
}
