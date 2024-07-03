#include <iostream>
#include <string>

using namespace std;

int getLength(string s, int repeat) {
    int length = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s[i + 1] == '(') {
            int nxtRepeat = s[i] - '0';
            int cnt = 1;
            string inner;
            for (int j = i + 2; j < s.size(); j++) {
                if (s[j] == '(')
                    cnt++;
                else if (s[j] == ')')
                    cnt--;

                inner += s[j];
                if (cnt == 0) {
                    i = j;
                    inner.pop_back();
                    length += getLength(inner, nxtRepeat);
                    break;
                }
            }
        } else {
            length++;
        }
    }

    return length * repeat;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    cout << getLength(s, 1);
}
