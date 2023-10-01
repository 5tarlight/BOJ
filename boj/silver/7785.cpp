#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<string> s;

    while (n--) {
        string a, b;
        cin >> a >> b;

        if (b == "enter")
            s.insert(a);
        else
            s.erase(a);
    }

    vector<string> v(s.size());
    for (auto &i : s) {
        v.push_back(i);
    }
    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << '\n';
    }
}
