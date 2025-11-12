array = [5, 2, 4, 6, 7, 5, 1, 3, 2]

def separation(array, left, right):
    supporting = array[right]
    i = left - 1
    for j in range(left, right):
        if array[j] < supporting:
            i += 1
            array[i], array[j] = array[j], array[i]
    array[i + 1], array[right] = array[right], array[i + 1]
    return i + 1

def quick_sort(array, left, right):
    if left < right:
        indx = separation(array, left, right)
        quick_sort(array, left, indx - 1)
        quick_sort(array, indx + 1, right)


right = len(array) - 1
left = 0
quick_sort(array, left, right)
print(array)
