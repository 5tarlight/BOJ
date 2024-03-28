#include <iostream>
#include <string>

using namespace std;

string graph[64];

string conq(int x1, int x2, int y1, int y2) {
    char prev = graph[x1][y1];
    bool isSame = true;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (prev != graph[i][j]) {
                isSame = false;
                break;
            }
        }
    }

    if (isSame)
        return string(1, prev);
    else {
        string s1 = conq(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
        string s2 = conq(x1, (x1 + x2) / 2, (y1 + y2) / 2 + 1, y2);
        string s3 = conq((x1 + x2) / 2 + 1, x2, y1, (y1 + y2) / 2);
        string s4 = conq((x1 + x2) / 2 + 1, x2, (y1 + y2) / 2 + 1, y2);

        return "(" + s1 + s2 + s3 + s4 + ")";
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    cout << conq(0, n - 1, 0, n - 1);
}
