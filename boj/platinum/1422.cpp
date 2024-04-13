#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct cmp {
    bool operator()(string &a, string &b) {
        string s1 = a + b;
        string s2 = b + a;

        return s1 > s2;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp());

    int maxl = 0;
    int maxi;
    for (int i = 0; i < n; i++) {
        if (a[i].size() > maxl) {
            maxl = a[i].size();
            maxi = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];

        if (i == maxi) {
            for (int j = 0; j < k - n; j++) {
                cout << a[i];
            }
        }
    }
}
