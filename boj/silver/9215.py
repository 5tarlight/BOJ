import sys
input = sys.stdin.readline

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

t = 1
while True:
    n = int(input())
    if n == 0:
        break

    a, b = 0, 1

    for _ in range(n):
        s = input().strip()

        if '/' in s:
            head, tail = s.split('/')
            tail = int(tail)

            if ',' in head:
                w, d = map(int, head.split(','))
                head = tail * w + d
            else:
                head = int(head)

            l = lcm(b, tail)
            a = a * (l // b) + head * (l // tail)
            b = l

            g = gcd(a, b)
            a //= g
            b //= g
        else:
            a += b * int(s)

    print(f'Test {t}: ', end='')
    if b == 1:
        print(a)
    elif a > b:
        print('{},{}/{}'.format(a // b, a % b, b))
    else:
        print('{}/{}'.format(a, b))
    t += 1