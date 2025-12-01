def foo(arr1):
    hash_table = {}
    for i in arr1:
        if i in hash_table:
            return i
        else:
            hash_table[i] = True

a =  ["а", "b", "с", "d", "с", "е", "f"]
print(foo(a))
