#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> graph;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        v.push_back(r);
        graph.push_back(r);
    }

    sort(graph.begin(), graph.end());

    graph.erase(unique(graph.begin(), graph.end()), graph.end());

    for (int i = 0; i < n; i++) {
        int index = lower_bound(graph.begin(), graph.end(), v[i]) - graph.begin();
        cout << index << ' ';
    }
}
