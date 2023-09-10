#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    cout << "<";

    while (!q.empty()) {
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();

        if (q.empty()) {
            cout << ">";
        } else {
            cout << ", ";
        }
    }
}
