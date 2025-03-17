def isPrime(n):
    if n % 3 == 0: return 3

    i = 5
    while i * i <= n:
        if n % i == 0:
            return i
        i += 2

    return -1

for _ in range(int(input())):
    n = input()

    tmp = isPrime(int(n))

    if tmp != -1:
        print(0, tmp)
    else:
        for i in range(len(n)):
            tmp = isPrime(int(n[:i] + n[i+1:]))

            if tmp != -1:
                print(i, tmp)
                break