#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> unheard;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        unheard.push_back(str);
    }
    sort(unheard.begin(), unheard.end());

    vector<string> unknown;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (binary_search(unheard.begin(), unheard.end(), str))
            unknown.push_back(str);
    }

    sort(unknown.begin(), unknown.end());

    cout << unknown.size() << '\n';
    for (const string& i : unknown)
        cout << i << '\n';
}
