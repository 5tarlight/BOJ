#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); }

int main() {
    fio();

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<char> st;
    for (int i = 0; i < n; ++i) {
        while (k > 0 && !st.empty() && st.back() < s[i]) {
            st.pop_back();
            k--;
        }
        st.push_back(s[i]);
    }

    while (k > 0 && !st.empty()) {
        st.pop_back();
        k--;
    }

    for (int i = 0; i < st.size(); ++i)
        cout << st[i];
}
