#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
char ch[15];

void backtrack(string s, int i, int d, int vowel, int consonant) {
    if (d == l) {
        if (vowel > 0 && consonant > 1)
            cout << s << '\n';
        return;
    }

    for (int j = i; j < c; j++) {
        bool isVowel = false;
        if (ch[j] == 'a' || ch[j] == 'e' || ch[j] == 'i' || ch[j] == 'o' || ch[j] == 'u') {
            isVowel = true;
        }
        if (isVowel) {
            backtrack(s + ch[j], j + 1, d + 1, vowel + 1, consonant);
        } else {
            backtrack(s + ch[j], j + 1, d + 1, vowel, consonant + 1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> ch[i];
    }

    sort(ch, ch + c);
    backtrack("", 0, 0, 0, 0);
}
