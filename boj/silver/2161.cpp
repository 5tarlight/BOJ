#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    queue<int> q;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() > 1) {
        cout << q.front() << ' ';
        q.pop();

        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}
