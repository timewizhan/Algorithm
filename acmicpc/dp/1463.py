v = int(input())
INF = 123456789123456789
ns = [INF] * (1000000 + 1)

ns[0] = ns[1] = 0
for i in range(2, v + 1):
    w = INF
    if i % 3 == 0:
        vt = int(i / 3)
        w = min(ns[vt] + 1, w)
    if i % 2 == 0:
        vt = int(i / 2)
        w = min(ns[vt] + 1, w)

    w = min(ns[i - 1] + 1, w)
    ns[i] = w

print(ns[v])

