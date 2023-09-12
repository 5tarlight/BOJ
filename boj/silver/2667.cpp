#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int map[25][25];
int visited[25][25];
vector<int> cntVec;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int cnt;

void dfs(int r, int c){
    for(int i = 0; i < 4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(nx >= N || nx < 0 || ny >= N || ny < 0)\
            continue;

        if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
            visited[nx][ny] = 1;
            cnt+=1;
            dfs(nx, ny);
        }
    }
}

int main() {
    int res=0;
    cin >> N;
    string str;

    for (int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < str.length(); j++) {
            visited[i][j] = 0;
            if(str[j] == '1'){
                map[i][j] = 1;
            } else map[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                visited[i][j] = 1;
                cnt = 1;                        //처음은 시작점 포함하므로 1로 초기화
                dfs(i,j);
                cntVec.push_back(cnt);
                res++;                          //단지 그룹 1개 탐색 끝남
            }
        }
    }

    sort(cntVec.begin(), cntVec.end());
    cout << res << "\n";

    for (int i : cntVec){
        cout << i << "\n";
    }
}