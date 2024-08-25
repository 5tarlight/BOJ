import sys
input = sys.stdin.readline

t = int(input())
for i in range(1, t + 1):
    a = sorted(list(map(int, input().split())))

    if a[2] >= a[0] + a[1]:
        print(f"Case #{i}: invalid!")
    elif a[0] == a[1] == a[2]:
        print(f"Case #{i}: equilateral")
    elif a[0] == a[1] or a[1] == a[2] or a[2] == a[0]:
        print(f"Case #{i}: isosceles")
    else:
        print(f"Case #{i}: scalene")