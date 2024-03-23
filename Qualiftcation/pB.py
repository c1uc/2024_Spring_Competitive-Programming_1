r1, r2, s1, s2 = input().split()
s1 = int(float(s1) * 100 + 0.5)
s2 = int(float(s2) * 100 + 0.5)
r1 = int(r1)
r2 = int(r2)

if (r1 - 1) / s1 < (r2 - 1) / s2:
    print("TAOYUAN")
elif (r1 - 1) / s1 > (r2 - 1) / s2:
    print("JAKARTA")
else:
    print("SAME")
