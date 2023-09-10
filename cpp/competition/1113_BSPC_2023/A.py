a, b = map(int, input().split())
k, x = map(int, input().split())

m = k-x if k-x > a else a
n = k+x if k+x < b else b

if m > b or n < a:
    print('IMPOSSIBLE')
else:
    print(n - m + 1)
