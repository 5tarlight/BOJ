#include <iostream>
#include <string>
#include <map>

using namespace std;

string a[10];
int n, k;
map<string, bool> m;
bool visited[10];

void backtrack(string s, int d) {
    if (d == k) {
        m[s] = true;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        backtrack(s + a[i], d + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    backtrack("", 0);

    cout << m.size();
}
