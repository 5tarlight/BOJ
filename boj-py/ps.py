n, k = map(int, input().split())

start = 0
digit = 1
end = 9

while k > end * digit:
    k -= digit * end
    start += end
    end *= 10
    digit += 1

ans = start + 1 + (k - 1) // digit

if ans > n:
    print(-1)
else:
    print(str(ans)[(k - 1) % digit])