import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

s = [input() for _ in range(n)]

for i in range(m):
    d = dict()

    for j in range(n):
        target = s[j][:i+1]
        if target not in d:
            d[target] = 1
        else:
            d[target] += 1

    mx = 1e9
    rev = ''
    for (ke, v) in d.items():
        if v < mx:
            mx = v
            rev = ke

    if mx <= k:
        print(i + 1)

        for nxt in rev:
            if nxt == 'R':
                print('S', end='')
            elif nxt == 'S':
                print('P', end='')
            else:
                print('R', end='')

        sys.exit(0)

print(-1)
