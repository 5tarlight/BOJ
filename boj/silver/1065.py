def check(n):
    digit = list(map(int, str(n)))
    l = len(digit)

    if l <= 2:
        return True

    diff = digit[1] - digit[0]
    for i in range(1, l - 1):
        if digit[i + 1] - digit[i] != diff:
            return False

    return True

x = int(input())
ans = 0
for i in range(1, x + 1):
    if check(i):
        ans += 1

print(ans)