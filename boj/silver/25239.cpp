#include <iostream>
#include <string>

using namespace std;

int parseTime(string &s) {
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    int min = (s[3] - '0') * 10 + (s[4] - '0');

    return (hour % 12) * 60 + min;
}

int addTime(int cur, int diff) {
    return (cur + diff) % 720;
}

int getArea(int time) {
    if (time <= 120)
        return 0;
    else if (time <= 240)
        return 1;
    else if (time <= 360)
        return 2;
    else if (time <= 480)
        return 3;
    else if (time <= 600)
        return 4;
    else
        return 5;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string start;
    cin >> start;
    int clock[6];
    bool sealed[6];
    for (int i = 0; i < 6; i++) {
        cin >> clock[i];
        sealed[i] = false;
    }
    int l;
    cin >> l;
    int cur = parseTime(start);
    while (l--) {
        double time;
        string action;
        cin >> time >> action;

        if (time >= 60)
            break;

        if (action == "10MIN")
            cur = addTime(cur, 10);
        else if (action == "30MIN")
            cur = addTime(cur, 30);
        else if (action == "50MIN")
            cur = addTime(cur, 50);
        else if (action == "2HOUR")
            cur = addTime(cur, 120);
        else if (action == "4HOUR")
            cur = addTime(cur, 240);
        else if (action == "9HOUR")
            cur = addTime(cur, 540);
        else if (action == "^") {
            sealed[getArea(cur)] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < 6; i++)
        if (!sealed[i])
            ans += clock[i];
    if (ans > 100)
        ans = 100;

    cout << ans;
}
