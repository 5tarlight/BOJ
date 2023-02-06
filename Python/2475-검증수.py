nums = map(int, input().split())


def pow(num):
    return num ** 2


print(sum(map(pow, nums)) % 10)
