alp, beta, m = [int(_) for _ in input().split()]

d = dict()

def pD(x):
    if x in d:
        return d[x]
    ans = 0
    if x == 0:
        ans = 2
    elif x == 1:
        ans = alp
    elif x % 2 == 0:
        ans = (pD(x // 2) ** 2 - 2 + m) % m
    else:
        ans = (pD(x // 2) * pD(x // 2 + 1) - alp + m) % m
    d[x] = ans
    return ans

print(pD(beta))
