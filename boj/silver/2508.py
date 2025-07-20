import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    input()
    r, c = map(int, input().split())
    s = [input().strip() for _ in range(r)]

    ans = 0
    for i in range(r):
        for j in range(c - 2):
            if s[i][j] == '>' and s[i][j + 1] == 'o' and s[i][j + 2] == '<':
                ans += 1

    for j in range(c):
        for i in range(r - 2):
            if s[i][j] == 'v' and s[i + 1][j] == 'o' and s[i + 2][j] == '^':
                ans += 1
    print(ans)