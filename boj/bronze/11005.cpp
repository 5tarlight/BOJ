#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int num, jin;
    cin >> num >> jin;
    stack<char> s;

    while (num) {
        int digit = num % jin;
        char ch;
        if (digit < 10)
            ch = '0' + digit;
        else
            ch  = 'A' + (digit - 10);
        num /= jin;
        s.push(ch);
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
