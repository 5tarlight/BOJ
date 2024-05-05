#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vll;
#define MOD 1'000'003

class Matrix {
public:
    int size;
    vll arr;

    Matrix(): size(0) {}
    Matrix(int n): size(n) {
        arr.resize(n, vector<ll>(n, 0));
    }

    Matrix operator*(const Matrix& other) {
        Matrix res(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    res.arr[i][j] += arr[i][k] * other.arr[k][j];
                    res.arr[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix pow(Matrix a, ll n) {
    if (n == 1) return a;
    if (n % 2 == 0) {
        Matrix half = pow(a, n / 2);
        return half * half;
    }
    return a * pow(a, n - 1);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, s, e, t;
    cin >> n >> s >> e >> t;
    s--; e--;
    Matrix m(n * 5);

    for (int i = 0; i < n; i++)
        for (int j = 1; j < 5; j++)
            m.arr[i * 5 + j][i * 5 + j - 1] = 1;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < n; j++) {
            int num = str[j] - '0';

            if (num == 1)
                m.arr[i * 5][j * 5] = 1;
            else if (num > 1)
                m.arr[i * 5][j * 5 + num - 1] = 1;
        }
    }

    Matrix ans = pow(m, t);

    cout << ans.arr[s * 5][e * 5];
}
