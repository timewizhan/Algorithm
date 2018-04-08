N = int(input())

arr = [[0] * 10 for i in range(N + 1)]
if N >= 1:
    for i in range(1, 10):
        arr[1][i] = 1

for i in range(2, N + 1):
    for j in range(10):
        if j - 1 >= 0:
            arr[i][j] += arr[i - 1][j - 1]
        if j + 1 <= 9:
            arr[i][j] += arr[i - 1][j + 1]

V = 1000000000
total = 0
for i in range(10):
    total += arr[N][i]

print(total % V)
