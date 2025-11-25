p1 = list(map(int, input().split()))
p2 = list(map(int, input().split()))
p3 = list(map(int, input().split()))

x = p1[0] ^ p2[0] ^ p3[0]
y = p1[1] ^ p2[1] ^ p3[1]

print(x, y)