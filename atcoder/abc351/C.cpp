#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    stack<long long> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s.push(x);

        while (s.size() >= 2) {
            long long a = s.top();
            s.pop();
            long long b = s.top();
            s.pop();
            if (a == b) {
                s.push(a + 1);
            } else {
                s.push(b);
                s.push(a);
                break;
            }
        }
    }

    cout << s.size();
}
