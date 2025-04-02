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

struct Date {
    int y, m, d;
};

bool isLeap(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int getDay(int y, int m) {
    static int dm[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && isLeap(y)) return 29;
    return dm[m];
}

Date getNext(const Date &d) {
    Date nd = d;
    nd.d++;
    if (nd.d > getDay(nd.y, nd.m)) {
        nd.d = 1;
        nd.m++;
        if (nd.m > 12) {
            nd.m = 1;
            nd.y++;
        }
    }
    return nd;
}

int dateKey(const Date &d) {
    return d.y * 10000 + d.m * 100 + d.d;
}

int main() {
    fio();

    Date start = { 1900, 1, 1, };
    Date end = { 2001, 11, 4 };
    vector<Date> dates;
    dates.push_back(start);
    while (true) {
        Date nd = getNext(dates.back());
        if (
                nd.y > end.y ||
                nd.y == end.y && nd.m > end.m ||
                nd.y == end.y && nd.m == end.m && nd.d > end.d
        ) break;
        dates.push_back(nd);
    }

    int n = dates.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[dateKey(dates[i])] = i;

    int termIdx = m[dateKey(end)];
    vector<bool> dp(n, false);

    for (int i = n - 1; i >= 0; i--) {
        if (i == termIdx) continue;
        bool win = false;

        int nxtIdx = i + 1;
        if (nxtIdx < n) {
            if (nxtIdx == termIdx)
                win = true;
            else
                if (!dp[nxtIdx])
                    win = true;
        }

        Date cur = dates[i];
        int ny = cur.y, nm = cur.m, nd = cur.d;
        nm++;
        if (nm > 12) { nm = 1; ny++; }
        if (nd <= getDay(ny, nm)) {
            Date can = { ny, nm, nd };
            int key = dateKey(can);

            if (m.find(key) != m.end()) {
                int canIdx = m[key];
                if (canIdx == termIdx)
                    win = true;
                else
                    if (!dp[canIdx])
                        win = true;
            }
        }
        dp[i] = win;
    }

    int t;
    cin >> t;
    while (t--) {
        int y, mm, d;
        cin >> y >> mm >> d;
        int key = y * 10000 + mm * 100 + d;

        if (key == dateKey(end)) {
            cout << "YES\n";
        } else {
            int idx = m[key];
            cout << (dp[idx] ? "YES\n" : "NO\n");
        }
    }
}
