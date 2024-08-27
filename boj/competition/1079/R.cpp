#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int plan[n], count = 0;

    for (int i = 0; i < n; i++)
        cin >> plan[i];

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a >= plan[i])
            count++;
    }

    cout << count;
}
