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

int n, m;
int kadane(int *a) {
    int maxSum = INT_MIN;
    int curSum = a[0];

    for (int i = 1; i < n; i++) {
        curSum = max(a[i], curSum + a[i]);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}

int main() {
    fio();

    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int maxSum = INT_MIN;

    for (int left = 0; left < m; left++) {
        int tmp[n];
        memset(tmp, 0, sizeof(tmp));

        for (int right = left; right < m; right++) {
            for (int i = 0; i < n; i++)
                tmp[i] += a[i][right];

            int curMax = kadane(tmp);
            maxSum = max(maxSum, curMax);
        }
    }

    cout << maxSum;
}
