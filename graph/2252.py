from collections import deque

s = input().split()
N = int(s[0])
M = int(s[1])

P = [[] for _ in range(N + 1)]
ingress = [0] * (N + 1)
for _ in range(M):
    s = list(map(int, input().split()))
    a = s[0]
    b = s[1]
    P[a].append(b)
    ingress[b] += 1

d = deque()
for i in range(1, N + 1):
    if ingress[i] < 1:
        d.append(i)

while len(d) != 0:
    here = d[0]
    d.popleft()
    print(here, end=" ")
    for there in P[here]:
        ingress[there] -= 1
        if not ingress[there]:
            d.append(there)






