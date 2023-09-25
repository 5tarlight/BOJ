#include <iostream>
#include <string>

using namespace std;

int getDistance(string &s1, string &s2, string &s3) {
    int distance = 0;

    for (int i = 0; i < 4; i++) {
        if (s1[i] != s2[i])
            distance++;
    }
    for (int i = 0; i < 4; i++) {
        if (s2[i] != s3[i])
            distance++;
    }
    for (int i = 0; i < 4; i++) {
        if (s3[i] != s1[i])
            distance++;
    }

    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string mbti[n];
        for (int j = 0; j < n; j++)
            cin >> mbti[j];

        if (n > 32) {
            cout << 0 << '\n';
            continue;
        }

        int distance = 123456789;
        for (int a = 0; a < n - 2; a++) {
            for (int b = a + 1; b < n - 1; b++) {
                for (int c = b + 1; c < n; c++) {
                    int dist = getDistance(mbti[a], mbti[b], mbti[c]);
                    if (dist < distance)
                        distance = dist;
                }
            }
        }

        cout << distance << '\n';
    }
}
