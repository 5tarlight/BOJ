#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        if (!dq.empty())
            if (dq.front().second <= i - l)
                dq.pop_front();

        while (!dq.empty() && dq.back().first > a[i])
            dq.pop_back();

        dq.push_back({a[i], i});

        cout << dq.front().first << ' ';
    }
}
