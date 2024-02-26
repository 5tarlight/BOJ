#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int h = 0;
    for (int i = 0; i < n; i++) {
        int r = 0;

        for (char ch : a[i]) {
            if (ch == 'X') {
                if (r > 1)
                    h++;
                r = 0;
            } else
                r++;
        }

        if (r > 1)
            h++;
    }

    int v = 0;
    for (int i = 0; i < n; i++) {
        int r = 0;

        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'X') {
                if (r > 1)
                    v++;
                r = 0;
            } else
                r++;
        }

        if (r > 1)
            v++;
    }

    cout << h << ' ' << v;
}
