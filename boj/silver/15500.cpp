#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s[2];
vector<pair<int, int>> ans;

void move(int a, int b) {
    int tmp = s[a - 1].top();
    s[a - 1].pop();
    if (b != 3)
        s[b - 1].push(tmp);

    ans.push_back({ a, b });
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int target = n;
    while (n--) {
        int num;
        cin >> num;
        s[0].push(num);
    }

    bool right = true;
    while (target) {
        if (right) {
            while (!s[0].empty()) {
                int tmp = s[0].top();
                if (tmp == target) {
                    move(1, 3);
                    target--;
                } else
                    move(1, 2);
            }
            if (s[0].empty())
                right = false;
        } else {
            while (!s[1].empty()) {
                int tmp = s[1].top();
                if (tmp == target) {
                    move(2, 3);
                    target--;
                } else
                    move(2, 1);
            }
            if (s[1].empty())
                right = true;
        }
    }

    cout << ans.size() << '\n';
    for (auto &p : ans)
        cout << p.first << ' ' << p.second << '\n';
}
