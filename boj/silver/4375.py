def solve(n):
    cnt = 1
    tmp = 1
    while True:
        if tmp % n == 0:
            print(cnt)
            return
        cnt += 1
        tmp = 10 * tmp + 1

while True:
    try:
        n = int(input())
    except:
        break
    solve(n)