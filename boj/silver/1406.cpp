#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    stack<char> left;
    stack<char> right;
    string s;
    cin >> s;
    for (char ch : s)
        left.push(ch);

    int m;
    cin >> m;
    while (m--) {
        char op;
        cin >> op;
        if (op == 'P') {
            char x;
            cin >> x;
            left.push(x);
        } else if (op == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if (op == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if (op == 'B')
            if (!left.empty())
                left.pop();
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}
