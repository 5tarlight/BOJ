#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<pair<int, int>> stk;
    int n;
    cin >> n;
    int s = -1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int temp = 0;

        while (!stk.empty() && a < stk.top().first) {
            temp += stk.top().second;
            s = max(s, temp * stk.top().first);
            stk.pop();
        }
        temp++;
        stk.emplace(a, temp);
    }

    int temp = 0;
    while (!stk.empty()) {
        temp += stk.top().second;
        s = max(s, temp * stk.top().first);
        stk.pop();
    }

    cout << s;
}
