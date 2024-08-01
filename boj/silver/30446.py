s = input()
n = int(s)

cnt = 0

num = 1

while True:
    p = int(str(num) + str(num)[::-1])
    if p <= n:
        cnt += 1

    p = int(str(num)[:-1] + str(num)[::-1])
    if p <= n:
        cnt += 1
    else:
        break

    num += 1

print(cnt)