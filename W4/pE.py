# pE - Euler's Number
ans = 1
n = int(input())
fact = 1
for i in range(1, n+1):
    fact *= i
    ans += 1/fact

print(ans)