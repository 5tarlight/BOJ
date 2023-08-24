#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string line;
    while (true) {
        getline(cin, line);
        if (line == ".")
            break;

        bool ok = true;
        stack<int> stack;
        // () 1 [] 2
        for (char c : line) {
            if (c == '(')
                stack.push(1);
            else if (c == '[')
                stack.push(2);
            else if (c == ')') {
                if (stack.empty() || stack.top() != 1) {
                    ok = false;
                    break;
                } else
                    stack.pop();
            } else if (c == ']') {
                if (stack.empty() || stack.top() != 2) {
                    ok = false;
                    break;
                } else
                    stack.pop();
            }
        }

        if (!stack.empty())
            ok = false;

        cout << (ok ? "yes" : "no") << "\n";
    }
}
