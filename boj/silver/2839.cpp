#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int count = 0;

    while (n > 0) {
        if (n % 5 == 0) {
            count += n / 5;
            n = 0;
        } else {
            count++;
            n -= 3;
        }
    }

    if (n)
        cout << -1;
    else
        cout << count;
}
