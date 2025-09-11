#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

vector<int> p;

void go(int n, bool center) {
    if (center) {
        for (int i = 0; i < p[n]; i++) cout << " ";
        return;
    }

    if (n == 0) {
        cout << '-';
        return;
    }

    go(n - 1, false);
    go(n - 1, true);
    go(n - 1, false);
}

int main() {
    fio();

    p.push_back(1);
    for (int i = 1; i <= 12; i++) {
        p.push_back(p.back() * 3);
    }

    int n;
    while (cin >> n) {
        go(n, false);
        cout << "\n";
    }
}
