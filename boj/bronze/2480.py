cnt = [0] * 7

for i in map(int, input().split()):
    cnt[i] += 1

def solve():
    last = -1
    for i in range(1, 7):
        if cnt[i] == 3:
            return 10000 + i * 1000
        elif cnt[i] == 2:
            return 1000 + i * 100
        elif cnt[i] == 1:
            last = i
    return 100 * last

print(solve())
