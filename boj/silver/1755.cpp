#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, string> m = {
    {0, "zero"},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"}
};

string to_string(int n) {
    string s;
    while (n) {
        s = m[n % 10] + " " + s;
        n /= 10;
    }
    return s;
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first < b.first;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    vector<pair<string, int>> v;
    for (int i = m; i <= n; i++) {
        string s = ::to_string(i);
        v.push_back({ s, i });
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ';
        if ((i + 1) % 10 == 0) cout << '\n';
    }
}