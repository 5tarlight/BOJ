import sys

def is_digit(ch):
    return '0' <= ch <= '9'

input = sys.stdin.readline

m = int(data[0])
strings = data[1:]

ans = []
for s in strings:
    num = 0
    i = 0
    while i < len(s):
        if not is_digit(s[i]):
            i += 1
            continue

        if s[i] == '0' and i < len(s) - 1 and is_digit(s[i + 1]):
            i += 1
            continue

        while i < len(s) and is_digit(s[i]):
            num = 10 * num + int(s[i])
            i += 1

        ans.append(num)
        num = 0

ans.sort()

for v in ans:
    print(v)
