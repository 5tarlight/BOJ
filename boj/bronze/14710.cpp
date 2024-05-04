#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if ((a % 30) * 12 == b)
        cout << 'O';
    else
        cout << 'X';
}
