n = int(input()) - 1
ans = 8
d = 1
while n > 0:
    n -= d
    d *= 2
    ans += 1

print(ans + 2)