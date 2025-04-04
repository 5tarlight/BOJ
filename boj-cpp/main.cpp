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

vector<int> manacher(const string &s) {
    string t;
    t.reserve(s.size()*2+1);
    for (char c : s) { t.push_back('#'); t.push_back(c); }
    t.push_back('#');
    int n = t.size(), center = 0, right = 0;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right) p[i] = min(right - i, p[mirror]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
            p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
    }
    return p;
}

int main() {
    fio();
    string s;
    cin >> s;
    dbg(manacher(s));
}
