#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blank;

void printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

// -1 : Invalid
// 0 : Unknown
// 1 : OK
int checkCol(int c) {
    bool visited[10];
    fill(visited, visited + 10, false);
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][c] == 0 || !visited[sudoku[i][c]])
            visited[sudoku[i][c]] = true;
        else
            return -1;
    }

    if (visited[0])
        return 0;
    else
        return 1;
}

int checkRow(int r) {
    bool visited[10];
    fill(visited, visited + 10, false);
    for (int i = 0; i < 9; i++) {
        if (sudoku[r][i] == 0 || !visited[sudoku[r][i]])
            visited[sudoku[r][i]] = true;
        else
            return -1;
    }

    if (visited[0])
        return 0;
    else
        return 1;
}

int checkSquare(int x, int y) {
    bool visited[10];
    fill(visited, visited + 10, false);
    for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
        for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {
            if (sudoku[i][j] == 0 || !visited[sudoku[i][j]])
                visited[sudoku[i][j]] = true;
            else
                return -1;
        }
    }

    if (visited[0])
        return 0;
    else
        return 1;
}

pair<int, int> points[9] = {
        { 0, 0 }, { 0, 3 }, { 0, 6 },
        { 3, 0 }, { 3, 3 }, { 3, 6 },
        { 6, 0 }, { 6, 3 }, { 6, 6 }
};
bool done = false;
void backtrack(int d) {
    if (done)
        return;

    if (d == blank.size()) {
        for (int i = 0; i < 9; i++) {
            if (checkCol(i) != 1 || checkRow(i) != 1)
                return;
            if (checkSquare(points[i].first, points[i].second) != 1)
                return;
        }

        done = true;
        printSudoku();
        return;
    }

    int x = blank[d].first;
    int y = blank[d].second;
    for (int i = 1; i <= 9; i++) {
        sudoku[x][y] = i;
        if (checkRow(x) != -1 && checkCol(y) != -1 && checkSquare(x, y) != -1)
            backtrack(d + 1);
        sudoku[x][y] = 0;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                blank.emplace_back(i, j);
        }
    }

    backtrack(0);
}
