n = int(input())
ans = 1

for i in range(1, n + 1, 2):
    ans *= i * (i + 1) // 2

for i in range(n // 2, 0, -1):
    ans //= i

print(ans)

