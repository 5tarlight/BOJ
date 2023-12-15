#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int ac, bc;
    cin >> ac >> bc;
    map<int, bool> a;

    for (int i = 0; i < ac; i++) {
        int n;
        cin >> n;
        a[n] = true;
    }
    int cnt = ac + bc;
    for (int i = 0; i < bc; i++) {
        int n;
        cin >> n;
        if (a.find(n) != a.end())
            cnt -= 2;
    }

    cout << cnt;
}
