while True:
    s = input()
    if s == '*': break

    good = True
    for d in range(len(s) - 2):
        v = set()
        if not good:
            break

        for i in range(len(s) - d - 1):
            p = s[i] + s[i + d + 1]
            if p in v:
                good = False
                break
            v.add(p)

    if good:
        print(s, 'is surprising.')
    else:
        print(s, 'is NOT surprising.')
