#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    queue<string> q[n];
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        string token;
        for (char j : s) {
            if (j == ' ') {
                q[i].push(token);
                token = "";
                continue;
            }

            token.push_back(j);
        }
        q[i].push(token);
    }

    string str;
    getline(cin, str);

    string word;
    bool ok = true;
    for (char ch : str) {
        if (ch == ' ') {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (!q[i].empty() && q[i].front() == word) {
                    q[i].pop();
                    found = true;
                }
            }
            if (!found) {
                ok = false;
                break;
            }

            word = "";
            continue;
        }

        word.push_back(ch);
    }

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (!q[i].empty() && q[i].front() == word) {
            q[i].pop();
            found = true;
        }
    }
    if (!found) {
        ok = false;
    }

    for (int i = 0; i < n; i++) {
        if (!q[i].empty()) {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "Possible";
    else
        cout << "Impossible";
}
