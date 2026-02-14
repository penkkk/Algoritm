def foo(s):
    hash_table = {}
    for i in s:
        if i not in hash_table:
            hash_table[i] = 1
        else:
            hash_table[i] += 1
    for i in s:
        if hash_table[i] == 1:
            return i
            
a =  "minimum"
print(foo(a))
