#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n; cin >> n;
    string s; cin >> s;

    bool lower = false, upper = false, digit = false, special = false;
    string sp = "!@#$%^&*()-+";

    for (char c : s) {
        if ('a' <= c && c <= 'z') lower = true;
        else if ('A' <= c && c <= 'Z') upper = true;
        else if ('0' <= c && c <= '9') digit = true;
        else if (sp.find(c) != string::npos) special = true;
    }

    int need = (!lower) + (!upper) + (!digit) + (!special);

    cout << max(need, 6 - n);
}