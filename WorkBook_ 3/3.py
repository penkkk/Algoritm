from random import randint

def num_generation(n): # генерируем десятичное число
    return [randint(1, 9)] + [randint(0,9) for i in range(n - 1)]

def additaion(n1, n2):
    p = [0] + n1 # первое число с незанчащим нулем
    r = [0] + n2 # второе число с незначащим нулем
    a = [(p[i] + r[i])%10 for i in range(len(p))] # результат
    b = [[0, 1][int((p[i + 1] + r[i + 1]) > 9)] for i in range(len(p) - 1)] + [0] # переносы
    if sum(b) != 0:
        return additaion(a, b)
    else:
        return a

def del_zero(ans): # функция удаления незначащих нулей
    while ans[0] == 0:
        ans.pop(0)
    return ans

n = int(input("Введите количество цифр в числе: "))
num_1 = num_generation(n)
num_2 = num_generation(n)

print(num_1)
print(num_2)

print(del_zero(additaion(num_1,num_2)))


