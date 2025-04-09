#include <bits/stdc++.h>
using namespace std;
void fio() { cin.tie(nullptr); ios::sync_with_stdio(false); }
template <class OStream, class T>
OStream &operator<<(OStream &os, const std::vector<T> &vec) {
    os << '[';
    for (auto v : vec) os << v << ',';
    os << ']';
    return os;
}
template <class OStream, class T, class U>
OStream &operator<<(OStream &os, const std::pair<T, U> &pa) {
    return os << '(' << pa.first << ',' << pa.second << ')';
}
#ifdef YEAHx4
#define dbg(x) std::cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#else
#define dbg(x) ((void)0)
#endif

int main() {
    fio();
    int board[19][19];
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    int dx[4] = {0, 1, 1, 1};
    int dy[4] = {1, 1, 0, -1};

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == 0) continue;
            int color = board[i][j];
            for (int d = 0; d < 4; d++) {
                int prevX = i - dx[d];
                int prevY = j - dy[d];
                if (prevX >= 0 && prevX < 19 && prevY >= 0 && prevY < 19 && board[prevX][prevY] == color)
                    continue;

                int count = 1;
                int nx = i;
                int ny = j;
                while (true) {
                    nx += dx[d];
                    ny += dy[d];
                    if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19 || board[nx][ny] != color)
                        break;
                    count++;
                }
                if (count == 5) {
                    int startX = i, startY = j;
                    if (d == 3) {
                        startX = i + 4;
                        startY = j - 4;
                    }
                    cout << color << "\n" << startX + 1 << " " << startY + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 0;
    return 0;
}
