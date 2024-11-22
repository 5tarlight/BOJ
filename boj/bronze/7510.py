for i in range(int(input())):
    a, b, c = map(int, input().split())
    ok = False

    if max([a, b, c]) == a:
        ok = a**2 == b**2 + c**2
    elif max([a, b, c]) == b:
        ok = b**2 == a**2 + c**2
    else:
        ok = c**2 == a**2 + b**2

    print(f"Scenario #{i + 1}:")
    if ok: print("yes\n")
    else: print("no\n")
