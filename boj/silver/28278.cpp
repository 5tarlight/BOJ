#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> s;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            s.push(x);
        } else if (op == 2) {
            if (s.empty())
                cout << "-1\n";
            else {
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op == 3)
            cout << s.size() << '\n';
        else if (op == 4)
            cout << (s.empty() ? "1\n" : "0\n");
        else {
            if (s.empty())
                cout << "-1\n";
            else
                cout << s.top() << '\n';
        }
    }
}
