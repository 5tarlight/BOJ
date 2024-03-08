#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int y, x;
    cin >> y >> x;
    char graph[y][x];
    for (int i = 0; i < y; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < x; j++) {
            graph[i][j] = s[j];
        }
    }

    bool found = false;
    if (x % 2 == 1) {
        int mid = x / 2;

        for (int i = 1; i < y - 1; i++) {
            if (graph[i][mid - 1] == 'X' && graph[i][mid + 1] == 'X' && graph[i][mid] == 'X') {
                graph[i][mid] = 'Y';
                graph[i][mid - 1] = 'W';
                graph[i][mid + 1] = 'W';
                found = true;
                break;
            }
        }
    } else {
        int mid1 = x / 2 - 1;
        int mid2 = mid1 + 1;

        for (int i = 1; i < y - 1; i++) {
            if (graph[i][mid1 - 1] == 'X' && graph[i][mid1] == 'X' && graph[i][mid2] == 'X' && graph[i][mid2 + 1] == 'X') {
                graph[i][mid1] = 'Y';
                graph[i][mid2] = 'Y';
                graph[i][mid1 - 1] = 'W';
                graph[i][mid2 + 1] = 'W';
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (graph[i][j] == 'X')
                    cout << 'B';
                else
                    cout << graph[i][j];
            }
            cout << endl;
        }
    }
}
