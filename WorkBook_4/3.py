array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
for i in range(len(array)):
    current = array[i]
    for j in range(0, i):
        if current < array[j]:
            array.insert(j, current)
            array.pop(i + 1)
            break
print(array)
