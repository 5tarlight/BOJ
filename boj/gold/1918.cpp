#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    stack<char> op;

    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            cout << ch;
            continue;
        }

        if (ch == '(')
            op.push('(');
        else if (ch == ')') {
            while (!op.empty() && op.top() != '(') {
                cout << op.top();
                op.pop();
            }
            op.pop();
        } else if (ch == '+' || ch == '-') {
            while (!op.empty() && op.top() != '(') {
                cout << op.top();
                op.pop();
            }
            op.push(ch);
        } else {
            while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                cout << op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }
}
