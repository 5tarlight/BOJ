#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        if (i == 0)
            arr[0] = v;
        else
            arr[i] = arr[i - 1] + v;
    }

    for (int i = 0; i < m; i++) {
        int s, e, sum;
        cin >> s >> e;

        if (s == 1)
            sum = arr[e - 1];
        else
            sum = arr[e - 1] - arr[s - 2];

        cout << sum << '\n';
    }
}
