#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int r, c;
    cin >> r >> c;

    vector<pair<int, int>> a; // { dst, idx }
    int rank[9];

    for (int k = 0; k < r; k++) {
        string s; cin >> s;
        for (int i = 1; i < c - 1; i++) {
            if (s[i] != '.') {
                a.push_back({ i, s[i] - '1' });
                break;
            }
        }
    }

    sort(a.begin(), a.end(), greater<>());

    int tmp = 1;
    rank[a[0].second] = 1;
    int prev = a[0].first;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].first == prev)
            rank[a[i].second] = tmp;
        else {
            rank[a[i].second] = ++tmp;
            prev = a[i].first;
        }
    }

    for (int i = 0; i < 9; i++)
        cout << rank[i] << '\n';
}
