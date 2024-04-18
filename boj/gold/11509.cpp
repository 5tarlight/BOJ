#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> arrow;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < arrow.size(); j++) {
            if (arrow[j] == a[i]) {
                found = true;
                arrow[j]--;
                break;
            }
        }

        if (!found) {
            arrow.push_back(a[i] - 1);
        }
    }

    cout << arrow.size();
}
