#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[50];
int r;

int dfs(int node) {
    if (node == r)
        return 0;
    if (graph[node].empty() || graph[node].size() == 1 && graph[node][0] == r)
        return 1;

    int cnt = 0;
    for (int n : graph[node]) {
        if (n == r)
            continue;
        cnt += dfs(n);
    }

    return cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int root;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            root = i;
            continue;
        }

        graph[num].push_back(i);
    }

    cin >> r;

    cout << dfs(root);
}
