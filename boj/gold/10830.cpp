#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix operator*(const matrix& a, const matrix& b) {
    int size = a.size();
    matrix result(size, vector<ll>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] %= 1000;
        }
    }

    return result;
}

matrix power(matrix& a, ll b) {
    int size = a.size();
    matrix result(size, vector<ll>(size));

    for (int i = 0; i < size; i++)
        result[i][i] = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            b--;
            result = result * a;
        } else {
            a = a * a;
            b /= 2;
        }
    }

    return result;
}

void printMatrix(const matrix& m) {
    int size = m.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << m[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll b;
    cin >> n >> b;
    matrix m(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];

    printMatrix(power(m, b));
}
