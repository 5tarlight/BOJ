#include <iostream>
#include <set>

using namespace std;

int n;
set<int> ans;
int roma[] = { 1, 5, 10, 50 };

void backtrack(int d, int idx, int v) {
    if (d == n) {
        ans.insert(v);
        return;
    }

    for (int i = idx; i < 4; i++) {
        backtrack(d + 1, i, v + roma[i]);
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    backtrack(0, 0, 0);
    cout << ans.size();
}
