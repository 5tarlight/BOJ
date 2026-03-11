#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    map<char, string> gen;
    vector<string> del;
    string t;

    string token;
    while (cin >> token) {
        if (token == "gen:") {
            string x, arrow, y;
            cin >> x >> arrow >> y;
            gen[x[0]] = y;
        } else if (token == "del:") {
            string x; cin >> x;
            del.push_back(x);
        } else if (token == "target:") {
            cin >> t;
        }
    }

    string cur = "A";
    bool ok = false;

    for (int i = 0; i < 10; i++) {
        string nxt;
        for (char c : cur) {
            if (gen.count(c))
                nxt += gen[c];
            else
                nxt += c;
        }
        cur = nxt;

        int l = cur.length();
        vector<bool> mark(l, false);

        for (const auto &d : del) {
            int dl = d.length();
            if (l < dl) continue;

            for (int i = 0; i <= l - dl; i++) {
                bool match = true;
                for (int j = 0; j < dl; j++) {
                    if (cur[i + j] != d[j]) {
                        match = false;
                        break;
                    }
                }

                if (match)
                    for (int j = 0; j < dl; j++)
                        mark[i + j] = true;
            }
        }

        nxt = "";
        for (int i = 0; i < l; i++) {
            if (!mark[i])
                nxt += cur[i];
        }

        cur = nxt;

        if (cur == t) {
            ok = true;
            break;
        }
    }

    if (ok) cout << "O";
    else cout << "X";
}
