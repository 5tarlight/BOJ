#include "bits/stdc++.h"

using namespace std;

int comb[11][11];

void calculateCombinations(int n) {
    for (int i = 0; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
}

int calculateTriangle(const vector<int>& row, int n) {
    vector<int> temp = row;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            temp[j] += temp[j + 1];
        }
    }
    return temp[0];
}

int main() {
    int n, f;
    cin >> n >> f;

    calculateCombinations(n);

    vector<int> row(n);
    for (int i = 0; i < n; i++) row[i] = i + 1;

    do {
        if (calculateTriangle(row, n) == f) {
            for (int i = 0; i < n; i++) {
                cout << row[i] << " ";
            }
            cout << endl;
            break;
        }
    } while (next_permutation(row.begin(), row.end()));

    return 0;
}