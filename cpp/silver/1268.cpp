#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int stu[n][5];
    int graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> stu[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < n; k++) {
                if (i == k)
                    continue;
                if (stu[i][j] == stu[k][j])
                    graph[i][k] = 1;
            }
        }
    }

    int max = 0, maxno = 1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++)
            if (graph[i][j] == 1)
                count++;

        if (count > max) {
            max = count;
            maxno = i + 1;
        }
    }

    cout << maxno;
}
