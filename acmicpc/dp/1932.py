N = int(input())

triangle = []
for _ in range(N):
    s = input().split(' ')

    vs = []
    for v in s:
        vs.append(int(v))
    triangle.append(vs)

# triangle.append([0] * (N + 1))
for i in reversed(range(N)):
    if i == 0:
        break

    for j in range(len(triangle[i]) - 1):
        maximum = max(triangle[i][j], triangle[i][j + 1])
        triangle[i - 1][j] += maximum

print(triangle[0][0])


