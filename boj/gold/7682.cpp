#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isFull(string &s) {
    for (int i = 0; i < 9; i++)
        if (s[i] == '.')
            return false;
    return true;
}

int isOver(string &s) {
    int ans = 0;

    if(s[0] == s[1] && s[1] == s[2] && s[0] != '.') ans++;
    if(s[3] == s[4] && s[4] == s[5] && s[3] != '.') ans++;
    if(s[6] == s[7] && s[7] == s[8] && s[6] != '.') ans++;
    if(s[0] == s[3] && s[3] == s[6] && s[0] != '.') ans++;
    if(s[1] == s[4] && s[4] == s[7] && s[1] != '.') ans++;
    if(s[2] == s[5] && s[5] == s[8] && s[2] != '.') ans++;
    if(s[0] == s[4] && s[4] == s[8] && s[0] != '.') ans++;
    if(s[2] == s[4] && s[4] == s[6] && s[2] != '.') ans++;

    return ans;
}

vector<char> getWinner(string s) {
    vector<char> c;
    if(s[0] == s[1] && s[1] == s[2] && s[0] != '.') c.push_back(s[0]);
    if(s[3] == s[4] && s[4] == s[5] && s[3] != '.') c.push_back(s[3]);
    if(s[6] == s[7] && s[7] == s[8] && s[6] != '.') c.push_back(s[6]);
    if(s[0] == s[3] && s[3] == s[6] && s[0] != '.')  c.push_back(s[0]);
    if(s[1] == s[4] && s[4] == s[7] && s[1] != '.')   c.push_back(s[1]);
    if(s[2] == s[5] && s[5] == s[8] && s[2] != '.')  c.push_back(s[2]);
    if(s[0] == s[4] && s[4] == s[8] && s[0] != '.')   c.push_back(s[0]);
    if(s[2] == s[4] && s[4] == s[6] && s[2] != '.')   c.push_back(s[2]);

    return c;
}

pair<int, int> cnt(string &s) {
    int o = 0, x = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] == 'O')
            o++;
        else if (s[i] == 'X')
            x++;
    }

    return { x, o };
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        string s;
        cin >> s;
        if (s == "end")
            break;

        if (isOver(s) > 0) {
            auto winner = getWinner(s);
            if (winner.size() > 2) {
                cout << "invalid\n";
                continue;
            } else {
                if (winner.size() == 2 && winner[0] != winner[1]) {
                    cout << "invalid\n";
                    continue;
                }
            }
            auto c = cnt(s);
            if (winner[0] == 'X') {
                if (c.first == 1 + c.second)
                    cout << "valid\n";
                else
                    cout << "invalid\n";
            } else {
                if (isFull(s))
                    cout << "invalid\n";
                else if (c.first == c.second)
                    cout << "valid\n";
                else
                    cout << "invalid\n";
            }
        } else {
            if (isFull(s)) {
                pair<int, int> c = cnt(s);
                if (c.first == c.second + 1)
                    cout << "valid\n";
                else
                    cout << "invalid\n";
            } else
                cout << "invalid\n";
        }
    }
}
