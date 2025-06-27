cnt = set()

def d(n):
    return n + sum(map(int, str(n)))

for i in range(1, 10001):
    cnt.add(d(i))

for i in range(1, 10001):
    if i not in cnt:
        print(i)