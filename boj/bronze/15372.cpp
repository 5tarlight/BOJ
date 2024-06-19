#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << n * n << '\n';
    }
}
