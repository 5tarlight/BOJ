#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c, m;
vector<pair<pair<int, int>, int>> list;
int truck[2001];
int delivered;

bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    if (a.first.second == b.first.second)
        return a.first.first < b.first.first;
    else
        return a.first.second < b.first.second;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> c >> m;

    for (int i = 0; i < m; i++) {
        int send, recv, box;
        cin >> send >> recv >> box;
        list.push_back({{ send, recv }, box});
    }

    sort(list.begin(), list.end(), cmp);

    for (int i = 0; i < list.size(); i++) {
        int from = list[i].first.first;
        int to = list[i].first.second;
        int size = list[i].second;

        int maxTruck = 0;

        for (int j = from; j < to; j++)
            maxTruck = max(truck[j], maxTruck);

        int cap = min(size, c - maxTruck);

        for (int j = from; j < to; j++)
            truck[j] += cap;

        delivered += cap;
    }

    cout << delivered;
}
