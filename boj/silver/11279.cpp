#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<>> q;

    while (n--) {
        int v;
        cin >> v;

        if (v == 0) {
            if (q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        } else {
            q.push(v);
        }
    }
}
