N = int(input())

ws = []
for i in range(N):
    ws.append(int(input()))

step = [[0]*N for k in range(2)]


for j in range(N):
    if j == 0:
        step[0][0] = ws[j]
    elif j == 1:
        step[0][1] = ws[j]
        step[1][1] = step[0][0] + ws[j]
    else:
        step[0][j] = max(step[0][j - 2], step[1][j - 2]) + ws[j]
        step[1][j] = step[0][j - 1] + ws[j]

print(max(step[0][N - 1], step[1][N - 1]))










