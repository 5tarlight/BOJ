#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    unordered_map<string, int> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s] = i;
    }

    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cases = n * (n - 1) / 2;
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (m[a[i]] < m[a[j]])
                ans++;

    cout << ans << '/' << cases;
}
