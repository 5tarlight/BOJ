_, x = map(int, input().split())
def c(n): return n < x


print(' '.join(map(str, list(filter(c, list(map(int, input().split())))))))
