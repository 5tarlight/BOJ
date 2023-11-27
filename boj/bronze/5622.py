w = input()

t = 0
for c in w:
    if c in 'ABC':
        t += 2
    elif c in 'DEF':
        t += 3
    elif c in 'GHI':
        t += 4
    elif c in 'JKL':
        t += 5
    elif c in 'MNO':
        t += 6
    elif c in 'PQRS':
        t += 7
    elif c in 'TUV':
        t += 8
    elif c in 'WXYZ':
        t += 9

t += len(w)
print(t)
     
