#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<>> minq;
priority_queue<int, vector<int>, less<>> maxq;
map<int, int> cnt;

void insert(int v) {
    minq.push(v);
    maxq.push(v);
    cnt[v]++;
}

void deleteMin() {
    if (!minq.empty()) {
        cnt[minq.top()]--;
        minq.pop();
    }
}

void deleteMax() {
    if (!maxq.empty()) {
        cnt[maxq.top()]--;
        maxq.pop();
    }
}

void clean() {
    while (!minq.empty() && cnt[minq.top()] == 0)
        minq.pop();
    while (!maxq.empty() && cnt[maxq.top()] == 0)
        maxq.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            char cmd;
            int n;

            cin >> cmd >> n;

            if (cmd == 'I')
                insert(n);
            else {
                if (n == 1)
                    deleteMax();
                else
                    deleteMin();
                clean();
            }
        }

        clean();
        if (maxq.empty() || minq.empty())
            cout << "EMPTY\n";
        else
            cout << maxq.top() << " " << minq.top() << '\n';

        if (i != t - 1) {
            while (!minq.empty())
                minq.empty();
            while (!maxq.empty())
                maxq.empty();
            cnt.clear();
        }
    }
}
