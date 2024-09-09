from math import gcd

t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    ans = -1

    for i in range(len(l)):
        for j in range(i + 1, len(l)):
            ans = max(ans, gcd(l[i], l[j]))

    print(ans)