#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<pair<int, int>> s;
    long long ans = 0;

    while (n--) {
        int x;
        cin >> x;
        int cnt = 1;

        while (!s.empty() && s.top().first <= x) {
            ans += s.top().second;

            if (s.top().first == x)
                cnt += s.top().second;
            s.pop();
        }

        if (!s.empty())
            ans++;

        s.push({x, cnt});
    }

    cout << ans;
}
