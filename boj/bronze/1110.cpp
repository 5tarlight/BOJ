#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int x = n, count = 0;
    do {
        x = (((x / 10) + (x % 10)) % 10) + (x % 10) * 10;
        count++;
    } while(x != n);

    cout << count;
}
