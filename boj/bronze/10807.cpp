#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int v;
    cin >> v;
    int cnt = 0;
    for (int r : arr)
        if (r == v)
            cnt++;

    cout << cnt;
}
