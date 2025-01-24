#include "bits/stdc++.h"

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int cnt[26] = {};
    for (int i = 0; i < n; i++)
        cnt[a[i] - 'a']++;
    for (int i = 0; i < n; i++) {
        if (cnt[b[i] - 'a'] == 0) {
            cout << "NO";
            return 0;
        }
        cnt[b[i] - 'a']--;
    }

    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO";
        return 0;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (isVowel(a[i])) continue;
        while (j < n && isVowel(b[j])) j++;

        if (j == n) {
            cout << "NO";
            return 0;
        }

        if (a[i] != b[j]) {
            cout << "NO";
            return 0;
        }
        j++;
    }

    cout << "YES";
}
