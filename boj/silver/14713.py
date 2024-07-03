import sys
input = sys.stdin.readline

n = int(input().strip())
queue = [[] for _ in range(n)]
for i in range(n):
    s = input().strip()
    queue[i] = list(s.split())

s = input().strip()
for word in s.split():
    found = False
    for i in range(n):
        if len(queue[i]) > 0 and queue[i][0] == word:
            queue[i].pop(0)
            found = True
            break

    if not found:
        print("Impossible")
        sys.exit()

ok = True
for i in range(n):
    if len(queue[i]) > 0:
        ok = False

if ok:
    print("Possible")
else:
    print('Impossible')
