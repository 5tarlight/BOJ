n, m = map(int, input().split())


def is_prime(num):
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            return False
    return True


result = []
for i in range(n, m + 1):
    if is_prime(i):
        result.append(str(i))

print('\n'.join(result))
