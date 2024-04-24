#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        stack<int> s;
        long long ans = -1;
        int h[n];
        for (int i = 0; i < n; i++)
            cin >> h[i];

        for (int i = 0; i < n; i++) {
            while (!s.empty() && h[i] < h[s.top()]) {
                long long height = h[s.top()];
                s.pop();
                long long width = i;

                if (!s.empty())
                    width = i - s.top() - 1;

                ans = max(ans, height * width);
            }
            s.push(i);
        }

        while (!s.empty()) {
            long long height = h[s.top()];
            s.pop();
            long long width = n;

            if (!s.empty())
                width = n - s.top() - 1;

            ans = max(ans, height * width);
        }

        cout << ans << '\n';
    }
}
