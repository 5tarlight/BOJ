#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    struct Algo { string name; int d; };
    vector<Algo> algo(n);
    for (int i = 0; i < n; i++) cin >> algo[i].name >> algo[i].d;

    int m; cin >> m;
    struct Member { string name; int t; };
    vector<Member> member(m);
    for (int i = 0; i < m; i++) cin >> member[i].name >> member[i].t;

    unordered_map<string, pair<string, string>> best;
    best.reserve(2 * m);

    for (auto &m : member) {
        vector<int> idx(n);

        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            int da = abs(algo[i].d - m.t);
            int db = abs(algo[j].d - m.t);
            if (da != db) return da < db;
            return algo[i].name < algo[j].name;
        });

        string t1 = algo[idx[0]].name;
        string t2 = algo[idx[1]].name;
        best[m.name] = {t1, t2};
    }

    int q; cin >> q;
    string dum; getline(cin, dum);

    string cur;
    while (q--) {
        string aa, bb, cc;
        cin >> aa >> bb >> cc;
        if (bb == "-") {
            cur = aa;
            cout << "hai!\n";
        } else {
            auto [t1, t2] = best[cur];
            cout << t2 << " yori mo " << t1 << '\n';
        }
    }
}
