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

int ansPin, ansMove;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(vector<string> &board, int moves, int pins) {
    if (pins < ansPin) {
        ansPin = pins;
        ansMove = moves;
    } else if (pins == ansPin && moves < ansMove) {
        ansMove = moves;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != 'o') continue;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                int nnx = i + 2 * dx[d];
                int nny = j + 2 * dy[d];

                if (nnx < 0 || nnx >= 5 || nny < 0 || nny >= 9) continue;
                if (board[nx][ny] == 'o' && board[nnx][nny] == '.') {
                    board[i][j] = '.';
                    char prev = board[nx][ny];
                    board[nx][ny] = '.';
                    board[nnx][nny] = 'o';

                    dfs(board, moves + 1, pins - 1);

                    board[i][j] = 'o';
                    board[nx][ny] = prev;
                    board[nnx][nny] = '.';
                }
            }
        }
    }
}

int main() {
    fio();

    int t;
    cin >> t;
    while (t--) {
        while (cin.peek() == '\n' || cin.peek() == '\r') cin.ignore();
        vector<string> board;

        for (int i = 0; i < 5; i++) {
            string l;
            getline(cin, l);
            board.push_back(l);
        }

        int pinCnt = 0;
        for (auto &s : board)
            for (auto &c : s)
                if (c == 'o') pinCnt++;

        ansPin = pinCnt;
        ansMove = 0;
        dfs(board, 0, pinCnt);

        cout << ansPin << ' ' << ansMove << '\n';
    }
}
