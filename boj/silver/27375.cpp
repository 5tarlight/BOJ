#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int n, k;
vector<pair<int, pair<int, int>>> a;
bool used[5][22];
int ans;

void back(int idx, int cur) {
    if (cur == k) {
        ans++; return;
    } else if (idx == a.size()) return;

    back(idx + 1, cur);

    bool ok = true;
    int w = a[idx].first;
    int s = a[idx].second.first;
    int e = a[idx].second.second;
    int kk = e - s + 1;

    for (int j = s; j <= e; j++) {
        if (used[w][j]) {
            ok = false; break;
        }
    }

    if (ok && cur + kk <= k) {
        for (int j = s; j <= e; j++) used[w][j] = true;
        back(idx + 1, cur + kk);
        for (int j = s; j <= e; j++) used[w][j] = false;
    }
}

int main() {
    fio();

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int w, s, e;
        cin >> w >> s >> e;
        w--; s--; e--;
        if (w == 4) continue;
        a.push_back({w, {s, e}});
    }

    back(0, 0);
    cout << ans;
}
