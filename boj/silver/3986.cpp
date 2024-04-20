#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        string str;
        cin >> str;
        stack<char> s;

        s.push(str[0]);
        for (int i = 1; i < str.size(); i++) {
            if (s.empty() || s.top() != str[i])
                s.push(str[i]);
            else
                s.pop();
        }

        if (s.empty())
            ans++;
    }

    cout << ans;
}
