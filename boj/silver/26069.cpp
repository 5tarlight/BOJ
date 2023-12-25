#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    map<string, bool> m;
    m["ChongChong"] = true;
    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;

        if (m.find(s1) != m.end())
            m[s2] = true;
        else if (m.find(s2) != m.end())
            m[s1] = true;
    }

    cout << m.size();
}
