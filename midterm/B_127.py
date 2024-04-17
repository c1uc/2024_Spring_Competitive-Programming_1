from decimal import *

getcontext().prec = 1000

a, b = input().split(' ')
print(Decimal(a) / Decimal(b))