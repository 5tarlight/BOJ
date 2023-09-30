#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int min = 2'000'000'001;
    int e = 0;
    for (int s = 0; s < n; s++) {
        while (e < n && a[e] - a[s] < m)
            e++;
        if (e == n)
            break;

        if (a[e] - a[s] < min)
            min = a[e] - a[s];
    }

    cout << min;
}
