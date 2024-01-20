#include <iostream>

using namespace std;

int inOrder[1001];
int preOrder[1001];
int t, n;

void postOrder(int start, int end, int pos) {
    for (int i = start; i < end; i++) {
        if (inOrder[i] == preOrder[pos]) {
            postOrder(start, i, pos + 1);
            postOrder(i + 1, end, pos + 1 + i - start);
            cout << preOrder[pos] << ' ';
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> preOrder[i];
        for (int i = 0; i < n; i++)
            cin >> inOrder[i];

        postOrder(0, n, 0);
        cout << '\n';
    }
}
