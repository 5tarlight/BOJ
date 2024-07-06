db = []
for i in range(1, 46):
    db.append(i * (i + 1) / 2)

t = int(input())
for _ in range(t):
    found = False
    n = int(input())
    for i in range(45):
        if found: break
        for j in range(i, 45):
            if found: break
            for k in range(j, 45):
                if db[i] + db[j] + db[k] == n:
                    found = True
                    print(1)
                    break
    if not found:
        print(0)