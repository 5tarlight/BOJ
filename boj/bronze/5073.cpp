#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c == 0)
            return 0;

        int m = max(a, max(b, c));

        if (m >= a + b + c - m)
            cout << "Invalid\n";
        else if (a == b & b == c && c == a)
            cout << "Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}
