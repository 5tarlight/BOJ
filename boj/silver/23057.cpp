#include <iostream>
#include <set>

using namespace std;

int n;
int a[20];
set<long long> m;

void backtrack(int d, long long sum) {
    if (d == n) {
        m.insert(sum);
        return;
    }

    backtrack(d + 1, sum + a[d]);
    backtrack(d + 1, sum);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    backtrack(0, 0);

    cout << sum - m.size() + 1;
}
