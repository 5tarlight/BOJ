n, m = map(int, input().split())
t, s = map(int, input().split())

home = -1
if n % 8 == 0:
    home = (n // 8 - 1) * s + n
else:
    home = (n // 8) * s + n

lib = -1
if m % 8 == 0:
    lib = t + (m // 8 - 1) * (s + 2*t) + m
else:
    lib = t + (m // 8) * (s + 2*t) + m

if home < lib:
    print('Zip')
    print(home)
else:
    print("Dok")
    print(lib)
