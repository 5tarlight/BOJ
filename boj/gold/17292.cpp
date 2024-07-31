#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

typedef pair<int, bool> t; // {number, color} where color is true for white (w) and false for black (b)
typedef pair<t, t> tt; // pair of two cards

bool isNear(int a, int b) {
    int diff = abs(a - b);
    return diff == 1 || diff == 14; // 1 and 15 are considered near
}

t parse(string s) {
    int num;
    if (s[0] >= '0' && s[0] <= '9')
        num = s[0] - '0';
    else
        num = s[0] - 'a' + 10;

    return { num, s[1] == 'w' };
}

struct cmp {
    bool operator()(tt &t1, tt &t2) {
        bool t1_near = isNear(t1.first.first, t1.second.first);
        bool t2_near = isNear(t2.first.first, t2.second.first);
        if (t1_near != t2_near)
            return t1_near > t2_near;

        bool t1_same = (t1.first.first == t1.second.first);
        bool t2_same = (t2.first.first == t2.second.first);
        if (t1_same != t2_same)
            return t1_same > t2_same;

        bool t1_same_color = (t1.first.second == t1.second.second);
        bool t2_same_color = (t2.first.second == t2.second.second);
        if (t1_same_color != t2_same_color)
            return t1_same_color > t2_same_color;

        int t1_max = max(t1.first.first, t1.second.first);
        int t2_max = max(t2.first.first, t2.second.first);
        if (t1_max != t2_max)
            return t1_max > t2_max;

        int t1_min = min(t1.first.first, t1.second.first);
        int t2_min = min(t2.first.first, t2.second.first);
        if (t1_min != t2_min)
            return t1_min > t2_min;

        bool t1_max_black = (t1.first.first > t1.second.first) ? !t1.first.second : !t1.second.second;
        bool t2_max_black = (t2.first.first > t2.second.first) ? !t2.first.second : !t2.second.second;
        return t1_max_black > t2_max_black;
    }
};

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string card;
    vector<string> inputs;
    while (getline(ss, card, ',')) {
        inputs.push_back(card);
    }

    vector<tt> cards;
    for (size_t i = 0; i < inputs.size(); ++i) {
        for (size_t j = i + 1; j < inputs.size(); ++j) {
            t first = parse(inputs[i]);
            t second = parse(inputs[j]);
            cards.push_back({first, second});
        }
    }

    sort(cards.begin(), cards.end(), cmp());

    for (auto &p : cards) {
        cout << (char)(p.first.first < 10 ? '0' + p.first.first : 'a' + p.first.first - 10) << (p.first.second ? 'w' : 'b');
        cout << (char)(p.second.first < 10 ? '0' + p.second.first : 'a' + p.second.first - 10) << (p.second.second ? 'w' : 'b');
        cout << endl;
    }

    return 0;
}
