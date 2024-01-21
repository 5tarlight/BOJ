n, q = map(int, input().split())
l = []

for i in range(1, n + 1):
    l.append((i, 0))
    
for _ in range(q):
    op, v = input().split()
    if op == '1':
        x = l[0][0]
        y = l[0][1]
        if v == 'U':
            y += 1
        elif v == 'R':
            x += 1
        elif v == 'D':
            y -= 1
        else:
            x -= 1
        
        l.insert(0, (x, y))
        l.pop()
    else:
        v = int(v) - 1
        print(l[v][0], l[v][1])