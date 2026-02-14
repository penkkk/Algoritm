def foo(arr1, arr2):
    hash_table = {}
    result = []
    for i in arr1:
        hash_table[i] = None
    for i in arr2:
        if i in hash_table:
            result.append(i)
    return result

a = [1, 2, 3, 4, 5]
b = [0, 2, 4, 6, 8]
print(foo(a, b))
