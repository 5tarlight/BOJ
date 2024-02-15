#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int city[50][50];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1)
                houses.emplace_back(i, j);
            else if (city[i][j] == 2)
                chickens.emplace_back(i, j);
        }
    }

    int perm[chickens.size()];
    for (int i = 0; i < chickens.size(); i++) {
        if (i < m)
            perm[i] = 1;
        else
            perm[i] = 0;
    }
    sort(perm, perm + chickens.size());

    int dist = 987654321;
    do {
        int d = 0;
        for (auto &h : houses) {
            int hd = 987654321;
            for (int i = 0; i < chickens.size(); i++) {
                if (perm[i] == 0)
                    continue;
                int ld = abs(h.first - chickens[i].first) + abs(h.second - chickens[i].second);
                if (ld < hd)
                    hd = ld;
            }
            d += hd;
        }

        if (d < dist)
            dist = d;
    } while (next_permutation(perm, perm + chickens.size()));

    cout << dist;
}