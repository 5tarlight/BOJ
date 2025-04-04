#include <bits/stdc++.h>

using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T> OStream &operator<<(OStream &os, const std::vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class OStream, class T, class U> OStream &operator<<(OStream &os, const std::pair<T, U> &pa) { return os << '(' << pa.first << ',' << pa.second << ')'; }
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

vector<int> getPi(const string &p) {
    int m = p.size(), len = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++) {
        while (len && p[i] != p[len]) len = pi[len - 1];
        if (p[i] == p[len]) len++;
        pi[i] = len;
    }
    return pi;
}

vector<int> kmp(const string &s, const string &p) {
    vector<int> pi = getPi(p), ans;
    int n = s.size(), m = p.size(), i = 0, j = 0;
    while (i < n) {
        if (s[i] == p[j]) {
            i++; j++;
            if (j == m) { ans.push_back(i - j); j = pi[j - 1]; }
        } else {
            if (j) j = pi[j - 1];
            else i++;
        }
    }
    return ans;
}

int main() {
    fio();
    string s, p;
    cin >> s >> p;
    dbg(kmp(s, p));
}
