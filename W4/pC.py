# pC - Generalized Recursive Functions
n = int(input().strip())

for i in range(n):
    v = [int(_) for _ in input().strip().split()]
    d = v[-1]
    v.pop()
    c = v[-1]
    v.pop()

    t = [[0 for __ in range(100)] for _ in range(100)]
    for x in range(100):
        for y in range(100):
            if x <= 0 or y <= 0:
                t[x][y] = d
                continue
            res = c
            for pos in range(0, len(v), 2):
                if x < v[pos] or y < v[pos + 1]:
                    res += d
                    continue
                res += t[x - v[pos]][y - v[pos + 1]]
            t[x][y] = res

    x = [int(_) for _ in input().strip().split()]
    for pos in range(0, len(x), 2):
        print(t[x[pos]][x[pos + 1]])
    print()
