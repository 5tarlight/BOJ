#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Trie {
    Trie* ch[26];
    bool end;

    Trie() {
        end = false;
        for (int i = 0; i < 26; i++)
            ch[i] = nullptr;
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
            delete ch[i];
    }

    void insert(const char *s) {
        if (!*s) {
            this->end = true;
            return;
        }
        int cur = *s - 'A';
        if (!ch[cur])
            ch[cur] = new Trie;
        ch[cur]->insert(s + 1);
    }

    bool find(const char *s) {
        if (!*s)
            return this->end;
        int cur = *s - 'A';
        if (!ch[cur])
            return false;
        return ch[cur]->find(s + 1);
    }

    bool findPrefix(const char *s) {
        if (!*s)
            return true;
        int cur = *s - 'A';
        if (!ch[cur])
            return false;
        return ch[cur]->findPrefix(s + 1);
    }
};

char graph[4][5];
int score;
string longest;
int cnt;
map<string, bool> found;
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
Trie trie;
bool visited[4][4];

void reset() {
    score = 0;
    longest = "";
    cnt = 0;
    found.clear();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            visited[i][j] = false;
}

void dfs(int x, int y, string s) {
    visited[x][y] = true;
    string cur = s + graph[x][y];

    // 현재 경로가 어떤 단어의 접두사도 아니면 더 이상 진행하지 않음.
    if (!trie.findPrefix(cur.c_str())) {
        visited[x][y] = false;
        return;
    }

    // 단어로 완성되었고, 아직 찾지 않은 경우 점수 및 결과 업데이트.
    if (trie.find(cur.c_str()) && found.count(cur) == 0) {
        int l = cur.length();
        if (l == 1 || l == 2)
            score += 0;
        else if (l == 3 || l == 4)
            score += 1;
        else if (l == 5)
            score += 2;
        else if (l == 6)
            score += 3;
        else if (l == 7)
            score += 5;
        else if (l == 8)
            score += 11;

        found[cur] = true;
        cnt++;
        if (l > longest.length())
            longest = cur;
        else if (l == longest.length() && cur < longest)
            longest = cur;
    }

    // 인접한 칸들을 계속 탐색.
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || visited[nx][ny])
            continue;
        dfs(nx, ny, cur);
    }

    visited[x][y] = false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int w;
    cin >> w;
    for (int i = 0; i < w; i++) {
        string s;
        cin >> s;
        trie.insert(s.c_str());
    }

    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++)
            cin >> graph[i];
        reset();
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                dfs(i, j, "");
        cout << score << ' ' << longest << ' ' << cnt << '\n';
    }
}
