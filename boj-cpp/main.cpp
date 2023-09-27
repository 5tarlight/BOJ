#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int perm[] = { 1, 1, 0, 0, 0 };
    int data[] = { 1, 2, 3, 4, 5 };

    sort(perm, perm + 5);

    do {
        for (int i = 0; i < 5; i++) {
            if (perm[i] == 1)
                cout << data[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(perm, perm + 5));
}
