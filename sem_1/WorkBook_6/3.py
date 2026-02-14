arr =[-1, 2, 3, 4, 7]
hash_table = dict()
need_sum = 5

for index, value in enumerate(arr):
    necessary = need_sum - value
    if necessary in hash_table:
        print(index, hash_table[necessary])
    else:
        hash_table[value] = index

