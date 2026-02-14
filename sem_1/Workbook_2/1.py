def euiklid_alg(num_1, num_2):
    difference = 0
    flag = False
    while flag == False:
        if num_1 == 0 or num_2 == 0:
            flag = True
            return max(num_1, num_2)
        if num_1 == num_2:
            flag = True
        elif num_1 < num_2:
            difference = num_2 - num_1
            num_2 = num_1
            num_1 = difference
        else:
            difference = num_1 - num_2
            num_1 = num_2
            num_2 = difference
    return num_1

n_1 = int(input())
n_2 = int(input())
n_3 = int(input())
n_4 = int(input())

print('Answer:', euiklid_alg(euiklid_alg(n_1, n_2), euiklid_alg(n_3, n_4)))
