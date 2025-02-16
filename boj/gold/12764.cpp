#include "bits/stdc++.h"

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> cnt;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    set<int> available_rooms;

    vector<pair<int, int>> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i].first >> in[i].second;
    }

    sort(in.begin(), in.end());

    for (int i = 0; i < n; i++) {
        auto [a, b] = in[i];

        while (!pq.empty() && pq.top().first <= a) {
            available_rooms.insert(pq.top().second);
            pq.pop();
        }

        if (!available_rooms.empty()) {
            int room = *available_rooms.begin();
            available_rooms.erase(available_rooms.begin());
            cnt[room]++;
            pq.push({ b, room });
        } else {
            cnt.push_back(1);
            pq.push({ b, cnt.size() - 1 });
        }
    }

    cout << cnt.size() << '\n';
    for (int i = 0; i < cnt.size(); i++) cout << cnt[i] << ' ';
}
