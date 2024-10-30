import sys

s = input()
l, r = s.split('=')
l1, l2 = l.split('+')

def isNum(c):
    return '0' <= c <= '9'


def cnt(s):
    c, h, o = 0, 0, 0
    for i in range(len(s)):
        if isNum(s[i]):
            continue

        if s[i] == 'C':
            if i < len(s) - 1 and isNum(s[i + 1]):
                c += int(s[i + 1])
            else:
                c += 1
        elif s[i] == 'H':
            if i < len(s) - 1 and isNum(s[i + 1]):
                h += int(s[i + 1])
            else:
                h += 1
        elif s[i] == 'O':
            if i < len(s) - 1 and isNum(s[i + 1]):
                o += int(s[i + 1])
            else:
                o += 1

    return c, h, o

l1c, l1h, l1o = cnt(l1)
l2c, l2h, l2o = cnt(l2)
rc, rh, ro = cnt(r)

for i in range(1, 11):
    for j in range(1, 11):
        for k in range(1, 11):
            if l1c * i + l2c * j == rc * k:
                if l1h * i + l2h * j == rh * k:
                    if l1o * i + l2o * j == ro * k:
                        print(i, j, k)
                        sys.exit(0)