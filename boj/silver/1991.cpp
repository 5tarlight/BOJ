#include <iostream>

using namespace std;

int n;
int lc[28];
int rc[28];

void preorder(int cur) {
    cout << (char)(cur - 1 + 'A');

    if (lc[cur])
        preorder(lc[cur]);
    if (rc[cur])
        preorder(rc[cur]);
}

void inorder(int cur) {
    if (lc[cur])
        inorder(lc[cur]);

    cout << (char)(cur - 1 + 'A');

    if (rc[cur])
        inorder(rc[cur]);
}

void postorder(int cur) {
    if (lc[cur])
        postorder(lc[cur]);
    if (rc[cur])
        postorder(rc[cur]);

    cout << (char)(cur - 1 + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        lc[a - 'A' + 1] = b == '.' ? 0 : b - 'A' + 1;
        rc[a - 'A' + 1] = c == '.' ? 0 : c - 'A' + 1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}
