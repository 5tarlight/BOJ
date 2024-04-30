#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    char op1, op2;
    if (a + b == c) {
        op1 = '+'; op2 = '=';
    } else if (a -b == c) {
        op1 = '-'; op2 = '=';
    } else if (a * b == c) {
        op1 = '*'; op2 = '=';
    } else if (a / b == c) {
        op1 = '/'; op2 = '=';
    } else if (a == b + c) {
        op1 = '='; op2 = '+';
    } else if (a == b - c) {
        op1 = '='; op2 = '-';
    } else if (a == b * c) {
        op1 = '='; op2 = '*';
    } else if (a == b / c) {
        op1 = '='; op2 = '/';
    }

    cout << a << op1 << b << op2 << c;
}
