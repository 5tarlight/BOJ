#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, string> map;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string k, v;
        cin >> k >> v;
        map[k] = v;
    }

    for (int i = 0; i < m; i++) {
        string k;
        cin >> k;
        cout << map[k] << '\n';
    }
}
