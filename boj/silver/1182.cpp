#include <iostream>

using namespace std;

int n, s;
int cnt = 0;
int nums[1'000'000];
bool visited[1'000'000];

void backtrack(int x, int sum) {
    if (x == n) {
        if (sum == s)
            cnt++;
        return;
    }

    backtrack(x + 1, sum);
    backtrack(x + 1, sum + nums[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    backtrack(0, 0);

    if (s == 0)
        cnt--;

    cout << cnt;
}
