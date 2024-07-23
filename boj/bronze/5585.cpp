#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n = 1000 - n;
    int cnt = 0;;
    int a[] = { 500, 100, 50, 10, 5, 1 };
    for (int v : a) {
        cnt += n / v;
        n %= v;
    }

    cout << cnt;
}
