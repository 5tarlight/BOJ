#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    stack<char> s;
    string m;
    cin >> m;
    for (char ch : m)
        s.push(ch);

    int k;
    cin >> k;

    while (k--) {
        if (s.empty())
            break;

        if (s.top() != '0')  {
            cout << "NO";
            return 0;
        }

        s.pop();
    }

    cout << "YES";
}
