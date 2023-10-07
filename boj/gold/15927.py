a = input()
if a.count(a[0])==len(a):
    print(-1)
elif a == a[::-1]:
    print(len(a) - 1)
else:
    print(len(a))
