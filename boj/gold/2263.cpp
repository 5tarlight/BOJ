#include <iostream>

using namespace std;

int indexes[100001];
int inOrder[100001];
int postOrder[100001];
int n;

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd)
        return;

    int root = indexes[postOrder[postEnd]];
    int gap = root - inStart;

    cout << inOrder[root] << ' ';

    preOrder(inStart, root - 1, postStart, postStart + gap - 1);
    preOrder(root + 1, inEnd, postStart + gap, postEnd - 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inOrder[i];
        indexes[inOrder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> postOrder[i];

    preOrder(1, n, 1, n);
}
