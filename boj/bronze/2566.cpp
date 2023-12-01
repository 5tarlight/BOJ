#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int max = -1;
    int maxx;
    int maxy;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num;
            cin >> num;
            if (num > max) {
                max = num;
                maxx = j + 1;
                maxy = i + 1;
            }
        }
    }

    cout << max << '\n';
    cout << maxy << ' ' << maxx;
}
