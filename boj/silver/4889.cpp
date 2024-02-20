#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 1; true; i++) {
        stack<char> s;
        string str;
        cin >> str;
        int cnt = 0;
        if (str[0] == '-')
            break;

        for (char ch : str) {
            if (!s.empty() && s.top() == '{' && ch == '}')
                s.pop();
            else
                s.push(ch);
        }

        while (!s.empty()) {
            char ch1 = s.top();
            s.pop();
            char ch2 = s.top();
            s.pop();

            if (ch1 == ch2)
                cnt++;
            else
                cnt += 2;

        }

        cout << i << ". " << cnt << '\n';
    }

}
