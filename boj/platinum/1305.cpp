#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int l;
    string str;
    cin >> l >> str;
    vector<int> pi(l, 0);

    int j = 0;
    for (int i = 1; i < l; i++) {
        while (j > 0 && str[j]!= str[i])
            j = pi[j - 1];
        if (str[j] == str[i])
            pi[i] = ++j;
    }

    cout << l - pi[l - 1];
}
