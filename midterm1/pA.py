a = int(input())
for _ in range(a):
    s = input()
    arr = [__.split(' ') for __ in s.split(',')]
    ans = 0
    for __ in arr:
        for ___ in __:
            if ___ == '': continue
            ans += int(___)
    print(ans)

