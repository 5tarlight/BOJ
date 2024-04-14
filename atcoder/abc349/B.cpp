#include <iostream>
#include <string>
#include <map>

using namespace std;

int cnt[26];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (char c : s) {
        cnt[c - 'a']++;
    }

    map<int, int> m;
    for (int i : cnt) {
        if (m[i])
            m[i]++;
        else
            m[i] = 1;
    }

    bool good = true;
    for (auto &p : m) {
        if (p.first == 0)
            continue;
        if (p.second != 0 && p.second != 2) {
            good = false;
            break;
        }
    }

    if (good) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
