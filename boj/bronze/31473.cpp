#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int asum = 0;
    int bsum = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        asum += a;
    }

    while (n--) {
        int b;
        cin >> b;
        bsum += b;
    }

    cout << bsum << ' ' << asum;
}
