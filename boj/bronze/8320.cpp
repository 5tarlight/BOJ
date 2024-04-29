#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
        for (int j = i; j * i <= n; j++)
            ans++;

    cout << ans;
}
