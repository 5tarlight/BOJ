st = set()
n = int(input())
s = input()

for i in range(n + 1):
    for ch in 'abcdefghijklmnopqrstuvwxyz':
        target = s[:i] + ch + s[i:]
        st.add(target)

print(len(st))