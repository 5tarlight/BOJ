prev = float(input())

while True:
    n = float(input())
    if n == 999:
        break
    diff = n - prev
    print(f"{diff:.2f}")
    prev = n