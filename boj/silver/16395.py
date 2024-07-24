n, k = map(int, input().split())
n -= 1
k -= 1
f = [1] * 31
for i in range(1, n + 1):
    f[i] = f[i - 1] * i

print(f[n] // f[k] // f[n - k])