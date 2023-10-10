#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int tree[10000];

void postOrder(int start, int end) {
    if (start >= end)
        return;
    else if (start == end - 1) {
        cout << tree[start] << '\n';
        return;
    }

    int i = start + 1;
    while (i < end) {
        if (tree[start] < tree[i])
            break;
        i++;
    }

    postOrder(start + 1, i);
    postOrder(i, end);
    cout << tree[start] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int i = 0;
    while (cin >> n) {
        tree[i] = n;
        i++;
    }

    postOrder(0, i);
}
