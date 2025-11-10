def resheto_sundarama(num):
    row = [i for i in range(1, (num - 1)//2 + 1)] # создаем массив с числами от 1 до (num - 1)//2 
    delite = [] # массив который заполним числами которые будем вычеркивать
    for i in range(1, max(row)): 
        for j in range(i, max(row)):
            s = i + j + 2 * i * j # двойным циклом в котором 1 <= i <= j получаем число
            if s in row: #если это число в нашем ряду то добавляем его в delite 
                delite.append(s)
    ans = [2] + [(x * 2 + 1) for x in row if x not in delite] # генерируем итоговый список в котором числа которые есть 
                                                        #в row но их нет в delite, а также каждое число запишем в виде 2n + 1
    return ans # возвращаем ответ
print(resheto_sundarama(80))