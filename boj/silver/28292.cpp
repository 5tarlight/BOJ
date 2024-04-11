#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n <= 2)
        cout << 1;
    else if (n <= 5)
        cout << 2;
    else
        cout << 3;
}
