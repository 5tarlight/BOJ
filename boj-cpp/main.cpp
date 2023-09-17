#include <iostream>

using namespace std;

bool isUniform(int **arr, int x, int y, int n) {
    int target = arr[x][y];

    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (arr[i][j] != target)
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int p[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    int white = 0;
    int blue = 0;
}
