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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans[n];
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= a[i])
            s.pop();

        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
