import re
import string


def solve():
    s = input()
    n = int(input())
    for _ in range(n):
        k = input()
        key = ""
        for sub in k:
            if sub in string.punctuation:
                key += "\\"
            key += sub
        pat = re.compile(key)
        # print(pat)
        print(len(re.findall(pat, s)))


a = int(input())
for _ in range(a):
    solve()

# 2
# ababa baabaa
# 3
# aba
# a
# !@#$^
# cdcdc#dc
# 1
# cdc
