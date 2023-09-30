#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int sum = a[0];
    int end = 0;
    int mn = 100'000'000;
    for (int start = 0; start < n; start++) {
        while (end < n && sum < s) {
            end++;
            sum += a[end];
        }
        if (end == n)
            break;

        mn = min(mn, end - start + 1);
        sum -= a[start];
    }

    if (mn == 100'000'000)
        mn = 0;

    cout << mn;
}
