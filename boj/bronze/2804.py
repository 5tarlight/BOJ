a, b = input().split()
l1, l2 = len(a), len(b)

ca, cb = -1, -1

for i in range(l1):
    for j in range(l2):
        if a[i] == b[j]:
            ca, cb = i, j
            break
    if ca != -1 and cb != -1:
        break

for i in range(l2):
    for j in range(l1):
        if i == cb:
            print(a[j], end='')
            continue
        if j == ca:
            print(b[i], end='')
            continue
        print('.', end='')
    print()
