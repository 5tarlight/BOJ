#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        vector<int> a;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num == 0)
                zeros++;
            else
                a.push_back(num);
        }

        sort(a.begin(), a.end());
        vector<int> ans;
        ans.push_back(a[0]);
        ans.push_back(a[1]);
        while (zeros--)
            ans.push_back(0);
        for (int i = 2; i < a.size(); i++)
            ans.push_back(a[i]);

        long long n1, n2;
        n1 = n2 = 0;
        bool first = true;
        for (int v : ans) {
            if (first)
                n1 = 10 * n1 + v;
            else
                n2 = 10 * n2 + v;
            first = !first;
        }

        cout << n1 + n2 << '\n';
    }
}
