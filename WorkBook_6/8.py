def foo(n):
    arr = [[0] * n for i in range(n)]
    for y in range(n):
        for x in range(n):
            if x == 0 or y == 0:
                arr[x][y] = 1
            else:
                arr[x][y] = arr[x-1][y] + arr[x][y - 1]
    return arr[n-1][n-1]

a = foo(4)

print(a)
