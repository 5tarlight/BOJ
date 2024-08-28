#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<int> s;

    while (n--) {
        int x;
        cin >> x;

        if (s.empty()) {
            s.push(x);
        } else {
            if ((s.top() + x) % 2 == 0)
                continue;
            s.push(x);
        }
    }

    cout << s.size();
}
