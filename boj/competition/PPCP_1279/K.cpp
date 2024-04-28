#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    deque<int> d;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            d.push_back(x);
            continue;
        }

        int size = d.size();
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < size / 2; i++)
            lsum += d[i];
        for (int i = size / 2; i < size; i++)
            rsum += d[i];

        if (lsum > rsum) {
            for (int i = size / 2; i < size; i++)
                d.pop_back();

            cout << rsum << '\n';
        } else {
            for (int i = 0; i < size / 2; i++)
                d.pop_front();

            cout << lsum << '\n';
        }
    }

    for (int x : d)
        cout << x << ' ';
}
