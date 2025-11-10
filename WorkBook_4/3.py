array = [5, 2, 4, 6, 7, 5, 1, 3, 2]
for i in range(len(array)):
    current = array[i]
    for j in range(len(array)):
        if current < array[j]:
            array.insert(j, current)
            array.pop(i)
            break
        elif current == array[j]:
            break
print(array)
