array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
n = len(array)
d = n // 2

while d > 0:
    for i in range(d, n):
        current = array[i]
        j = i
        while (j >= d) and array[j - d] > current:
            array[j] = array[j - d]
            j -= d
        array[j] = current
    d //= 2

print(array)
