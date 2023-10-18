#include <iostream>
#include <string>

using namespace std;

#define LEN 26

bool learn[LEN];
int n, k;
string str[50];
int maxWord = 0;

void backtrack(int idx, int d) {
    if (d == k) {
        int c = 0;
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (char ch : str[i]) {
                if (!learn[ch - 'a']) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                c++;
        }

        if (c > maxWord)
            maxWord = c;

        return;
    }

    for (int i = idx + 1; i < LEN; i++) {
        if (learn[i])
            continue;

        learn[i] = true;
        backtrack(i, d + 1);
        learn[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    if (k < 5) {
        cout << 0;
        return 0;
    } else if (k == LEN) {
        cout << n;
        return 0;
    }

    learn['a' - 'a'] = true;
    learn['n' - 'a'] = true;
    learn['t' - 'a'] = true;
    learn['i' - 'a'] = true;
    learn['c' - 'a'] = true;
    backtrack(0, 5);

    cout << maxWord;
}
