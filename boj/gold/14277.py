a, b, c, d, u = map(int, input().split())

if a > u:
    ans1 = 0
else:
    ans1 = (u - a) // b + 1

ans2 = 0
temp = c
while temp <= u:
    if not (temp >= a and (temp - a) % b == 0):
        ans2 += 1
    temp *= d
    if d == 1:
        break

print(ans1 + ans2)
