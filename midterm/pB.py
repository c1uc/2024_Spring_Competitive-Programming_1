from decimal import *

getcontext().prec = 1000

a, b = input().split(' ')
c = Decimal(a) / Decimal(b)
res = c.as_tuple()
# print(res)
print('-' if res.sign == 1 else '', end='')

e = res.exponent

if(e >= 0):
    print(''.join(map(str, res.digits)) + '0' * e)
else:
    digs = [_ for _ in map(str, res.digits)]
    digs = (['0'] * (-len(digs) - e + 1)) + digs
    print(''.join(digs[:e]) + "." + ''.join(digs[e:]))


# 0.000000000000000000000000000000000000000000001 0.1
# 0.123456789123456798 1000