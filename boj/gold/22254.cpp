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

int n, x;
vector<int> a;

int solve(int k) {
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < k; i++) pq.push(0);

    for (int i = 0; i < n; i++) {
        int t = pq.top();
        pq.pop();
        pq.push(t + a[i]);
    }

    int ans = 0;
    while (!pq.empty()) {
        ans = pq.top();
        pq.pop();
    }
    return ans;
}

int main() {
    fio();
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (solve(m) <= x) r = m;
        else l = m + 1;
    }

    cout << l;
}
