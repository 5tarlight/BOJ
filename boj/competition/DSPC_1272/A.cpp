#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == 0 || b == 0)
        cout << c * c - a - b;
    else {
        int temp = a + b;
        int i;
        for (i = 1; i * i < temp; i++);
        cout << i;
    }
}
