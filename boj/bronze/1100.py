ans = 0
for i in range(8):
    s = input()
    if i % 2 == 0:
        ans += s[::2].count('F')
    else:
        ans += s[1::2].count('F')

print(ans)