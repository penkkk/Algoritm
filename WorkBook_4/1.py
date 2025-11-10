array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
flag = 1
while flag == 1:
    flag = 0
    for i in range(len(array) - 1):
        if array[i] > array[i + 1]:
            array[i], array[i + 1] = array[i + 1], array[i]
            flag = 1
print(array)
