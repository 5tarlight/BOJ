#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    while (m--) {
        int a, b;
        cin >> a >> b;
        int temp;
        temp = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = temp;
    }

    for (int v : arr)
        cout << v << ' ';
}
