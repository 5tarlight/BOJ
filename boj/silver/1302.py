n = int(input())
cnt = {}

for _ in range(n):
    s = input()
    if s in cnt:
        cnt[s] += 1
    else:
        cnt[s] = 1

arr = []

for k, v in cnt.items():
    arr.append((-v, k))

arr.sort()

print(arr[0][1])