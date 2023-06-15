num = int(input())

for i in range(1, num + 1):
    snum = i + sum(map(int, str(i)))

    if snum == num:
        print(i)
        break
    elif i == num:
        print(0)
