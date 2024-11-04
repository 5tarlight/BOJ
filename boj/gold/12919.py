ss = input()
tt = input()

def can(s, t):
    if len(s) < len(t): return False
    elif len(s) == len(t): return s == t

    a1, a2 = False, False
    if s[-1] == 'A': a1 = can(s[:-1], t)
    if s[0] == 'B': a2 = can(s[1:][::-1], t)

    return a1 or a2

print(int(can(tt, ss)))
