#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[n], b[m], c[n + m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    int ai = 0;
    int bi = 0;
    for (int i = 0; i < n + m; i++) {
        if (ai == n)
            c[i] = b[bi++];
        else if (bi == m)
            c[i] = a[ai++];
        else {
            if (a[ai] < b[bi])
                c[i] = a[ai++];
            else
                c[i] = b[bi++];
        }
    }

    for (int i = 0; i < n + m; i++)
        cout << c[i] << ' ';
}
