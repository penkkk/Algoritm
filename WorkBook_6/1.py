size = 7
data = [86, 90, 27, 29, 38, 30, 40]
hash_table = [None] * size
for i in data:
    hsh = i % 7
    position = hsh
    while hash_table[position] is not None:
        position = (position + 1) % 7
    hash_table[position] = i
print(hash_table)
