#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

struct cmp {
    bool operator()(string &a, string &b) {
        if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i])
                    continue;
                return a[i] < b[i];
            }
            return false;
        }
        return a.size() < b.size();
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m;
    cin >> m;
    vector<string> ans;
    while (m--) {
        string s;
        cin >> s;

        string num = "";
        for (int i = 0; i < s.size(); i++) {
            if (!isDigit(s[i]))
                continue;

            if (s[i] == '0' && num == "" && i < s.size() - 1 && isDigit(s[i + 1]))
                continue;

            num = num + s[i];

            if (i == s.size() - 1 || !isDigit(s[i + 1])) {
                ans.push_back(num);
                num = "";
            }
        }
    }

    sort(ans.begin(), ans.end(), cmp());

    for (auto v : ans)
        cout << v << '\n';
}
