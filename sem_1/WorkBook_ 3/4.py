from random import randint

def num_generation(n): #генерация дес. числа
    return [randint(1, 9)] + [randint(0,9) for i in range(n - 1)]

def multiplication(n1, n2):
    n1, n2 = n1[::-1], n2[::-1] # для удобства перевернем числа
    res = [[0] * (len(n1) + len(n2)) for i in range(len(n1))] # массив куда будет записываться результат
    for i in range(len(n1)):
        a = 0
        for j in range(len(n2)):
            current = (n1[i] * n2[j] + a) % 10 # оставляем в текущем разряде только остаток от деления 
            if (n1[i] * n2[j] + a) > 9: 
                a = (n1[i] * n2[j] + a) // 10 # запоминаем сколько мы преенесем в следующий разряд
            else:
                a = 0
            res[i][j] = current # записываем в разряд значение
        if a != 0: # если на последнем шаге получили перенос то записываем его
            res[i][len(n2)] = a 
    ans = []
    for i in range(len(n1)): # увеличиваем наши промежуточные результаты на разряд начиная со второго
        ans.append([0]*i + res[i])
    return ans # как итог получаем двумерный массив промежуточных чисел в обратном порядке
                # который нужно просуммировать столбиком

def additaion(rows): # функция сложения в столбик, анологичная в первом задание, только для нескольких слагаемых сразу
    mx_len = max(len(row) for row in rows) # считываем максимальную длину числа
    rows = [row + [0]*(mx_len - len(row)) for row in rows] # делаем чтобы каждое число имело одинаковое количество цифр
    res = [0 for i in range(mx_len)] # промежуточный результат
    a = 0
    for i in range(mx_len): # проходися по каждому элементу
        temp = 0
        for j in range(len(rows)): # проходимся по каждому столбцу
            temp += (rows[j][i]) # скалдываем соответсвующие цифры из каждого столбца
        temp += a # добавляем перенос (если он был)
        res[i] = temp % 10 # записываем в разряд остаток от деления на 10 нашего результаа
        if temp > 9: # если нужен перенос
            a = temp // 10 # запоминаем перенос
        else:
            a = 0
    if a != 0: # если в конце вышел перенос, то добавляем его в конец
        res.append(a)
    return res[::-1] # итоговый ответ - это перевернутый промежуточный результат

def del_zero(ans): # функция удаления незначащих нулей
    while ans[0] == 0:
        ans.pop(0)
    return ans
            
n = int(input('Введите количество цифр в числах: '))
n1 = num_generation(n)
n2 = num_generation(n)
print(n1, n2)
ans = del_zero(additaion(multiplication(n1, n2)))
print(ans)

