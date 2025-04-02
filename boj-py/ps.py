for _ in range(int(input())):
    d, n, s, p = map(int, input().split())
    non = n * s
    q = d + n * p

    if non == q:
        print("does not matter")
    elif non > q:
        print("parallelize")
    else:
        print("do not parallelize")
