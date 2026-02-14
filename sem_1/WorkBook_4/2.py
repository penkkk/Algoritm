array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
flag = 1
start = 0
end = len(array) - 1
step = 1
while flag == 1:
    flag = 0
    swap = -1
    if step == 1:
        for i in range(start, end, step):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                flag = 1
                swap = i
        end = swap
    else:
        for i in range(end, start, step):
            if array[i] < array[i - 1]:
                array[i], array[i - 1] = array[i - 1], array[i]
                flag = 1
                swap = i
        start = swap
    step *= -1
print(array)
