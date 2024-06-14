n, m = map(int, input().split())
a = []
if m > 0:
    a = list(map(int, input().split()))

digit = [0] * 10
ans = []
cnt = 0

for i in a:
    digit[i] += 1

def backtrack(d):
    global n

    if d == n:
        global cnt
        cp = digit[:]
        ok = True
        for i in ans:
            if cp[i] > 0:
                cp[i] -= 1
        if any(cp):
            ok = False

        if ok:
            cnt += 1
        return

    for i in range(10):
        ans.append(i)
        backtrack(d + 1)
        ans.pop()

backtrack(0)
print(cnt)