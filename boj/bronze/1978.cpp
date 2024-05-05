#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    int ans = 0;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (num > 1 && isPrime) {
            ans++;
        }
    }

    cout << ans;
}
