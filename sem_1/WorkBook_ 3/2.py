from random import randint

def num_generation(n): # функция генерации числа
    return [randint(0, 1) for i in range(n)]

def additaion(n1, n2):
    p = [0] + n1 # первое число с незначащим нулем, используем его для последнего переноса
    r = [0] + n2 # второе число аналогично первому
    a = [[0, 1][(p[i] + r[i])%2] for i in range(len(p))] # промежуточные результаты
    b = [[0, 1][int((p[i + 1] + r[i + 1]) == 2)] for i in range(len(r) - 1)] + [0] # переносы
    if sum(b) != 0: # если строка переносов не нулевая
        return additaion(a, b) # вызываем функцию еще раз
    else:
        return a # возвращаем a - результат

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
