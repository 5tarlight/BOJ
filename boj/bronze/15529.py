n = int(input())
a = list(map(int, input().split()))

ans = -1
for i in range(n - 1):
    for j in range(i+1, n):
        num = a[i] * a[j]
        tmp = num
        while tmp > 9:
            if tmp % 10 == (tmp // 10 % 10) + 1:
                tmp //= 10
            else:
                break

        if tmp < 10:
            ans = max(ans, num)



print(ans)