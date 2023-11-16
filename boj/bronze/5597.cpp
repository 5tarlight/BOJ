#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool submit[31];
    fill(submit, submit + 31, false);
    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        submit[n] = true;
    }

    for (int i = 1; i <= 30; i++)
        if (!submit[i])
            cout << i << '\n';
}
