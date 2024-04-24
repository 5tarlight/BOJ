#include <iostream>
#include <vector>

using namespace std;

int ans = -1;
vector<int> v;
int a, b;
int arr[10];
bool used[10];
int maxD;

void backtrack(int d) {
    if (d == maxD) {
        int x = 0;
        for (int i = 0; i < v.size(); i++) {
            x = x * 10 + v[i];
        }

        if (x >= b)
            return;
        else if (x > ans)
            ans = x;
    }

    for (int i = 0; i < maxD; i++) {
        if (!used[i]) {
            if (d == 0 && arr[i] == 0)
                continue;

            used[i] = true;
            v.push_back(arr[i]);
            backtrack(d + 1);
            v.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    maxD = to_string(a).size();
    for (int i = 0; i < maxD; i++) {
        arr[i] = a % 10;
        a /= 10;
    }

    backtrack(0);

    cout << ans;
}
