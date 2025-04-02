import math

d, h, w = map(int, input().split())
scale = d / math.sqrt(h * h + w * w)
h, w = math.floor(h * scale), math.floor(w * scale)
print(h, w)