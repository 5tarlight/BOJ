def toDec(a):
    ans = int(a[0])
    ans = 10 * ans + int(a[1])
    ans = 10 * ans + int(a[2])
    ans = 10 * ans + int(a[3])

    return ans

def toStr(a):
    ans = ''
    if a < 10:
        ans = '000' + str(a)
    elif a < 100:
        ans = '00' + str(a)
    elif a < 1000:
        ans = '0' + str(a)
    else:
        ans = str(a)

    return ans

t = int(input())
for _ in range(t):
    s = input()
    cnt = 0

    while s != '6174':
        s = toStr(toDec(sorted(s, reverse=True)) - toDec(sorted(s)))
        cnt += 1
    print(cnt)