#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;

bool cmp(string &a, string &b) {
    if (a.size() == b.size()) {
        int asum = 0;
        int bsum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                asum += a[i] - '0';
            }
            if (b[i] >= '0' && b[i] <= '9') {
                bsum += b[i] - '0';
            }
        }

        if (asum == bsum) {
            return a < b;
        } else {
            return asum < bsum;
        }
    } else {
        return a.size() < b.size();
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
}
