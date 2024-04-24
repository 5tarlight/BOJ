#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(string &s1, string &s2) {
        return s1 + s2 > s2 + s1;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    priority_queue<string, vector<string>, cmp> pq;

    while (n--) {
        string s;
        cin >> s;
        pq.push(s);
    }

    while (!pq.empty()) {
        string cur = pq.top();
        pq.pop();

        cout << cur[0];

        int len = cur.length();
        if (len > 1)
            pq.push(cur.substr(1, len - 1));
    }
}
