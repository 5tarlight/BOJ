#include <iostream>

using namespace std;

void draw(int i, int j, int size) {
    if ((i / size) % 3 == 1 && (j / size) % 3 == 1) {
        cout << ' ';
    } else {
        if (size / 3 == 0)
            cout << '*';
        else
            draw(i, j, size / 3);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            draw(i, j, n);
        cout << '\n';
    }
}
