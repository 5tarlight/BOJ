t = int(input())
for _ in range(t):
    n = int(input())

    good = True
    nsum = 0

    for i in range(1, n):
        if n % i != 0: continue

        nsum += i

        ssum = 0
        for j in range(1, i):
            if i % j == 0:
                ssum += j

        if ssum > i:
            good = False
            break

    if good and nsum > n:
        print("Good Bye")
    else:
        print("BOJ 2022")