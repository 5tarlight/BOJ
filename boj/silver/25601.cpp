#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> parent;

bool find(string &str, string &target) {
    if (parent.find(str) == parent.end())
        return false;
    else if (parent[str] == target)
        return true;
    else
        return find(parent[str], target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a >> b;

        if (n == 0) {
            if (find(a, b) || find(b, a))
                cout << 1;
            else
                cout << 0;
        } else {
            parent[a] = b;
        }
    }
}
