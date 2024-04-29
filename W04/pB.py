# pB - Wizard of Odds
def solve():
    [a, b] = list(map(int, input().strip().split()))
    if a <= 2 ** b:
        print('Your wish is granted!')
    else:
        print('You will become a flying monkey!')


solve()
