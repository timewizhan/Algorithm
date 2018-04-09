from collections import deque

s = input().split()
m = int(s[0])
n = int(s[1])

arr = [[0] * m for _ in range(n)]

q = deque()
for i in range(n):
    vs = list(map(int, input().split()))
    for j in range(m):
        arr[i][j] = vs[j]
        if vs[j] == 1:
            q.append((i, j))

# print(arr)
# print(q)

day = 1
while len(q) != 0:
    v = q.popleft()
    row = v[0]
    col = v[1]

    u = d = l = r = 0
    if row - 1 >= 0:
        if arr[row - 1][col] != -1 and arr[row - 1][col] == 0:
            arr[row - 1][col] = arr[row][col] + 1
            u = arr[row - 1][col]
            q.append((row - 1, col))
    if row + 1 < n and arr[row + 1][col] != -1:
        if arr[row + 1][col] != -1 and arr[row + 1][col] == 0:
            arr[row + 1][col] = arr[row][col] + 1
            d = arr[row + 1][col]
            q.append((row + 1, col))
    if col - 1 >= 0 and arr[row][col - 1] != -1:
        if arr[row][col - 1] != -1 and arr[row][col - 1] == 0:
            arr[row][col - 1] = arr[row][col] + 1
            l = arr[row][col - 1]
            q.append((row, col - 1))
    if col + 1 < m and arr[row][col + 1] != -1:
        if arr[row][col + 1] != -1 and arr[row][col + 1] == 0:
            arr[row][col + 1] = arr[row][col] + 1
            r = arr[row][col + 1]
            q.append((row, col + 1))

    day = max(day, max(max(u, d), max(l, r)))
    # print(day)

def sol(arr, n, m):
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 0:
                return False

    return True

if not sol(arr, n, m):
    print(-1)
else:
    print(day - 1)
# print(arr)





