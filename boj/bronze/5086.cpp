#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == b)
            return 0;

        if (b % a == 0)
            cout << "factor\n";
        else if (a % b == 0)
            cout << "multiple\n";
        else
            cout << "neither\n";
    }
}
