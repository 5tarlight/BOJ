n, m, k = map(int, input().split())
m = []

for _ in range(n):
    m.append(input())
    
count = 0
for line in m:
    for t in line.split('1'):
        if len(t) >= k:
            count += len(t) - k + 1

print(count)
