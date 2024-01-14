#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, less<>> maxq;
    priority_queue<int, vector<int>, greater<>> minq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (i == 0)
            maxq.push(num);
        else if (i == 1) {
            if (num > maxq.top())
                minq.push(num);
            else {
                minq.push(maxq.top());
                maxq.pop();
                maxq.push(num);
            }
        } else {
            maxq.push(num);

            if (maxq.top() > minq.top()) {
                maxq.pop();
                minq.push(num);

                if (minq.size() > maxq.size()) {
                    maxq.push(minq.top());
                    minq.pop();
                }
            }
            if (maxq.size() - minq.size() > 1) {
                minq.push(maxq.top());
                maxq.pop();
            }
        }

        cout << maxq.top() << '\n';
    }
}