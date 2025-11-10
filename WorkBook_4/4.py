array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
for i in range(len(array)):
    for j in range(i + 1, len(array)):
        if array[i] > array[j]:
            array[i], array[j] = array[j], array[i]
            
print(array)
