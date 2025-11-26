n = input()

ans = 0
while len(n) != 1:
    ans += 1
    n = str(sum(map(int, n)))

print(ans)
if n in ['3', '6', '9']:
    print("YES")
else:
    print("NO")