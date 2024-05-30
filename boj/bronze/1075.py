n = int(input())
f = int(input())

rest = n % f
if n % 100 < rest:
    ans = (n + f - rest) % 100
else:
    ans = (n - rest) % 100 % f

if ans < 10:
    print('0', end='')
print(ans)