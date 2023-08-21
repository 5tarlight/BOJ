n = int(input())

l = []

for _ in range(n):
    age, name = input().split()
    age = int(age)
    l.append((age, name))

for (age, name) in sorted(l, key=lambda m: m[0]):
    print(age, name)
