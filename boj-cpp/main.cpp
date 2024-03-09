#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;
    int n, d;
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++)
            temp += p[j];
    }
}
