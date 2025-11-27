def convert(n, d):
    tmp = ''
    while n > 0:
        tmp += str(n % d)
        n //= d

    return tmp[::-1]

s = int(input())

found = False
for i in range(2, 11):
    t = convert(s, i)
    if t == t[::-1]:
        found = True
        print(i, t)

if not found:
    print("NIE")