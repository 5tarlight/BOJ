#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    char answer[50];

    int streak = 0;
    bool impossible = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            if (streak == 4) {
                answer[i - 3] = 'A';
                answer[i - 2] = 'A';
                answer[i - 1] = 'A';
                answer[i] = 'A';
            } else if (streak == 2) {
                answer[i - 2] = 'B';
                answer[i - 1] = 'B';
            } else if (streak != 0) {
                impossible = true;
                break;
            }

            answer[i] = '.';
            streak = 0;
            continue;
        } else {
            streak++;

            if (streak == 4) {
                answer[i - 3] = 'A';
                answer[i - 2] = 'A';
                answer[i - 1] = 'A';
                answer[i] = 'A';
                streak = 0;
                continue;
            }
        }
    }

    int i = str.size() - 1;
    if (streak == 4) {
        answer[i - 3] = 'A';
        answer[i - 2] = 'A';
        answer[i - 1] = 'A';
        answer[i] = 'A';
        streak = 0;
    } else if (streak == 2) {
        answer[i - 1] = 'B';
        answer[i] = 'B';
        streak = 0;
    } else {
        impossible = true;
    }

    if (impossible)
        cout << -1;
    else {
        for(int i = 0; i < str.size(); i++)
            cout << answer[i];
    }
}
