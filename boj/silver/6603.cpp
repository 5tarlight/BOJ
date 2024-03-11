#include <iostream>

using namespace std;

int n;
int a[12];
int b[6];

void backtrack(int d, int s) {
    if (d == 6) {
        for (int i : b)
            cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = s; i < n; i++) {
        b[d] = a[i];
        backtrack(d + 1, i + 1);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        backtrack(0, 0);
        cout << '\n';
    }
}
