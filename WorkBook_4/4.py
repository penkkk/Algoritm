array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
for i in range(len(array) - 1):
    min_index = i
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    if min_index != i:
        array[i], array[min_index] = array[min_index], array[i]         
print(array)
