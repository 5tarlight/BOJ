from collections import Counter

s = input().strip()
c = Counter(s)
odd = [k for k in c if c[k] % 2 == 1]

if len(odd) > 1:
    print("I'm Sorry Hansoo")
    exit()

res = []
for ch in sorted(c):
    res.append(ch * (c[ch] // 2))

mid = '' if not odd else odd[0]
half = ''.join(res)
print(half + mid + half[::-1])
