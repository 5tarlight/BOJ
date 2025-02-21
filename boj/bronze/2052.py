import decimal
from decimal import Decimal

n = int(input())
decimal.getcontext().prec = n + 10
ans = Decimal(1) / Decimal(2 ** n)
print(f"{ans:.{n}f}")