#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<char> dq;
        char f;
        cin >> f;
        dq.push_front(f);
        n--;

        while (n--) {
            char ch;
            cin >> ch;

            if (ch <= dq.front())
                dq.push_front(ch);
            else
                dq.push_back(ch);
        }

        for (char c : dq)
            cout << c;
        cout << '\n';
    }
}
