#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    char graph[n][n];
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            graph[i][j] = line[j];
        }
    }

    int hx, hy;
    bool found = false;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (graph[i][j] == '*') {
                if (graph[i - 1][j] == '*' && graph[i + 1][j] == '*' && graph[i][j - 1] == '*' && graph[i][j + 1] == '*') {
                    hx = i;
                    hy = j;
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;
    }

    cout << hx + 1 << ' ' << hy + 1 << '\n';

    int la = 0;
    for (int i = hy - 1; i >= 0; i--) {
        if (graph[hx][i] == '*') {
            la++;
        } else {
            break;
        }
    }

    int ra = 0;
    for (int i = hy + 1; i < n; i++) {
        if (graph[hx][i] == '*') {
            ra++;
        } else {
            break;
        }
    }

    int m = 0;
    int end;
    for (int i = hx + 1; i < n; i++) {
        if (graph[i][hy] == '*') {
            m++;
            end = i;
        } else {
            break;
        }
    }

    int ll = 0;
    for (int i = end + 1; i < n; i++) {
        if (graph[i][hy - 1] == '*') {
            ll++;
        } else {
            break;
        }
    }

    int rl = 0;
    for (int i = end + 1; i < n; i++) {
        if (graph[i][hy + 1] == '*') {
            rl++;
        } else {
            break;
        }
    }

    cout << la << ' ' << ra << ' ' << m << ' ' << ll << ' ' << rl;
}
