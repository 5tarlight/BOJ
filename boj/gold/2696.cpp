#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<>> down;
        priority_queue<int, vector<int>, less<>> up;
        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;

            if (i % 2 == 1) {
                up.push(num);

                if (!up.empty() && !down.empty()) {
                    if (up.top() > down.top()) {
                        down.push(up.top());
                        up.pop();
                        up.push(down.top());
                        down.pop();
                    }
                }

                ans.push_back(up.top());
            } else {
                down.push(num);
            }
        }

        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
        cout << '\n';
    }
}
