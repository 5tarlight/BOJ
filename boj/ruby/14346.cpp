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

const double INF = DBL_MAX;
const double EPS = 1e-7;

vector<double> islands;

double getY(double x, double y) {
    double ret = 0.0;
    for (double i : islands) {
        double d = x * x + (y - i) * (y - i);
        if (d < EPS) return INF;
        ret += 1.0 / d;
    }
    return ret;
}

// Euler Lagrange Equation
double ele(double x, double y, double pos) {
    double temp = pos * pos + 1;
    double ret = 1.0;
    double p1 = 0.0, p2 = 0.0;
    for (double i : islands) {
        double d = x * x + (y - i) * (y - i);
        ret += 1.0 / d;
        p1 += (y - i) / (d * d);
        p2 += (x + (y - i) * pos) / (d * d);
    }
    return temp * (pos * p2 - temp * p1) * 2 / ret;
}

pair<double, double> calc(double x, double y, double pos) {
    double ret = 0.0;
    for (int i = 0; i < 2000; i++) {
        if (y > 13 || y < -13) return { INF, y };
        ret += (getY(x, y) + 1) * sqrt(pos * pos + 1) / 100;
        x += 0.01;
        y += pos / 100;
        pos += ele(x, y, pos) / 100;
    }
    return {ret, y};
}

double bsearch(double x, double y, double l, double r) {
    double ret = INF;
    while (fabs(r - l) / 2 > EPS) {
        double mid = (l + r) / 2;
        auto temp = calc(-10, x, mid);
        ret = temp.first;
        if (temp.second < y) l = mid;
        else r = mid;
    }
    return ret;
}

int main() {
    fio();

    int t;
    cin >> t;
    cout << fixed << setprecision(2);
    for (int tc = 1; tc <= t; tc++) {
        int n;
        double a, b;
        cin >> n >> a >> b;
        islands.resize(n);
        for (int i = 0; i < n; i++) cin >> islands[i];

        vector<double> slopes;
        slopes.push_back(-2);
        slopes.push_back(2);
        for (double i : islands)
            slopes.push_back((i - a) / 10);
        sort(slopes.begin(), slopes.end());

        dbg(slopes);

        double result = INF;
        for (size_t j = 0; j < slopes.size() - 1; j++) {
            double tmp = bsearch(a, b, slopes[j], slopes[j + 1]);
            result = min(result, tmp);
        }

        cout << "Case #" << tc << ": " << result << "\n";
    }
}
