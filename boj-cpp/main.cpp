#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parents;
unordered_map<string, int> sizes;

string find(string x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find(parents[x]);
}

void unite(string x, string y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parents[x] = y;
        sizes[y] += sizes[x];
    }
    cout << sizes[y] << '\n';
}

void reset() {
    parents.clear();
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        reset();
        int f;
        cin >> f;
        while (f--) {
            string a, b;
            cin >> a >> b;
            if (parents.find(a) == parents.end()) {
                parents[a] = a;
                sizes[a] = 1;
            }
            if (parents.find(b) == parents.end()) {
                parents[b] = b;
                sizes[b] = 1;
            }

            unite(a, b);
        }
    }
}
