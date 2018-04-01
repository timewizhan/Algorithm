dp = [(0,0)]*40

def fibo(n):
    if n == 0:
        return (1, 0)
    if n == 1:
        return (0, 1)
    if dp[n - 1] != (0, 0):
        s1 = dp[n - 1]
    else:
        s1 = fibo(n - 1)
        dp[n - 1] = s1

    if dp[n - 2] != (0, 0):
        s2 = dp[n - 2]
    else:
        s2 = fibo(n - 2)
        dp[n - 2] = s2
    return (s1[0] + s2[0], s1[1] + s2[1])

T = int(input())

for i in range(0, T):
    N = int(input())
    sol = fibo(N)
    print('{} {}'.format(sol[0], sol[1]))

