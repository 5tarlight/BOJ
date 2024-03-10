#include <iostream>

using namespace std;

int graph[3][3];

bool isDone() {
    for (int i = 0; i < 3; i++) {
        if (graph[i][0] == graph[i][1] && graph[i][1] == graph[i][2] && graph[i][0] != 0)
            return true;
    }
    for (int i = 0; i < 3; i++) {
        if (graph[0][i] == graph[1][i] && graph[1][i] == graph[2][i] && graph[0][i] != 0)
            return true;
    }
    if (graph[0][0] == graph[1][1] && graph[1][1] == graph[2][2] && graph[0][0] != 0)
        return true;
    if (graph[0][2] == graph[1][1] && graph[1][1] == graph[2][0] && graph[0][2] != 0)
        return true;
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int start;
    cin >> start;
    for (int _ = 0; _ < 9; _++) {
        int x, y;
        cin >> x >> y;

        graph[x - 1][y - 1] = start;
        if (isDone()) {
            cout << start;
            return 0;
        }

        start = 3 - start;
    }

    cout << 0;
}
