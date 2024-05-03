#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int sudoku[9][9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> sudoku[i][j];

        bool isCorrect = true;
        for (int i = 0; i < 9; i++) {
            bool check[10] = {false, };
            for (int j = 0; j < 9; j++) {
                if (check[sudoku[i][j]]) {
                    isCorrect = false;
                    break;
                }
                check[sudoku[i][j]] = true;
            }
            if (!isCorrect)
                break;
        }

        if (isCorrect) {
            for (int i = 0; i < 9; i++) {
                bool check[10] = {false, };
                for (int j = 0; j < 9; j++) {
                    if (check[sudoku[j][i]]) {
                        isCorrect = false;
                        break;
                    }
                    check[sudoku[j][i]] = true;
                }
                if (!isCorrect)
                    break;
            }
        }

        if (isCorrect) {
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    bool check[10] = {false, };
                    for (int k = i; k < i + 3; k++) {
                        for (int l = j; l < j + 3; l++) {
                            if (check[sudoku[k][l]]) {
                                isCorrect = false;
                                break;
                            }
                            check[sudoku[k][l]] = true;
                        }
                        if (!isCorrect)
                            break;
                    }
                    if (!isCorrect)
                        break;
                }
                if (!isCorrect)
                    break;
            }
        }

        cout << "Case " << k << ": " << (isCorrect ? "CORRECT" : "INCORRECT") << '\n';
    }
}
