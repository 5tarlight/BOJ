n, k = map(int, input().split())

a = []
for _ in range(n):
    i, g, s, b = map(int, input().split())
    a.append((-g, -s, -b, i))

a.sort()

prev = (-1, -1, -1, -1)
rank = 0
tmp = 1
for i in a:
    if i[0] == prev[0] and i[1] == prev[1] and i[2] == prev[2]:
        tmp += 1

        if i[3] == k:
            print(rank)
            break

        continue

    prev = i
    rank += tmp
    tmp = 1

    if i[3] == k:
        print(rank)
        break
