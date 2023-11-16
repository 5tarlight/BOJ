#include <iostream>
#include <algorithm>

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
        reverse(arr + a - 1, arr + b);
    }

    for (int v : arr)
        cout << v << ' ';
}
