#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    int size = n / k;

    for (int i = 0; i < n; i += size)
        sort(a + i, a + i + size);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
