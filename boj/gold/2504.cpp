#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    stack<char> st;
    stack<int> val;
    int ans = 0;

    for (char c : s) {
        if (c == '(' || c == '[') {
            st.push(c);
            val.push(0);
            continue;
        }

        if(st.empty()) {
            cout << 0;
            return 0;
        }

        int tmp = 0;
        while (!st.empty() && st.top() != '(' && st.top() != '[') {
            tmp += val.top(); val.pop();
            st.pop();
            if (st.empty()) {
                cout << 0;
                return 0;
            }
        }

        if (c == ')' && st.top() != '(' || c == ']' && st.top() != '[') {
            cout << 0;
            return 0;
        }

        st.pop(); val.pop();
        int cur = c == ')' ? 2 : 3;
        val.push(tmp == 0 ? cur : tmp * cur);
        st.push('#');
    }

    while (!st.empty()) {
        if (st.top() != '#') {
            cout << 0;
            return 0;
        }

        ans += val.top(); val.pop();
        st.pop();
    }

    cout << ans;
}
