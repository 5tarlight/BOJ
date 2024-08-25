import sys

d = int(input())
a = []
for _ in range(d):
    a.append(int(input()))

money = 100
stock = 0

for i in range(d):
    if i == 0:
        if d == 1:
            print(100)
            sys.exit(0)

        if a[i] < a[i+1]:
            stock = money // a[i]
            money = money % a[i]
            if stock > 100000:
                money += (stock - 100000) * a[i]
                stock = 100000
    elif i == d - 1:
        money += a[i] * stock
        stock = 0
    else:
        if a[i - 1] < a[i] < a[i + 1]:
            continue
        elif a[i - 1] < a[i] < a[i + 1]:
            continue

        if a[i] < a[i + 1]:
            stock += money // a[i]
            money = money % a[i]
            if stock > 100000:
                money += (stock - 100000) * a[i]
                stock = 100000
        else:
            money += a[i] * stock
            stock = 0

print(money)