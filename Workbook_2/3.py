from math import floor
def resheto(num): # функция для получения решета из прошлой задачи
    simple_numbers = [i for i in range(2, num + 1)] # массив чисел от 2 до num
    prime_index = 0
    while prime_index < len(simple_numbers):
        p = simple_numbers[prime_index] #берем простой элемент
        simple_numbers = [i for i in simple_numbers if i == p or i % p != 0] #оставляем подходяищие эл-ты
        # оставляем в этом массиве только числа которые не делятся на p
        prime_index += 1 # увеличивая индекс берем следующе p и проделываем ту же операцию 
    return simple_numbers

def ferm(num):
    divs = [] # создаем пустой список всех делителей
    if num in resheto(num): # если число простое
        divs.append(num) # добавляем его одного в список делителей и возвращаем списко сразу
        return divs
    elif num ** 0.5 == int(num**0.5): # если число полный квадрат раскладываем самостоятельно
        d1 = d2 = int(num**0.5)
    else: # иначе реализовываем алгоритм ферма
        m = floor(num ** 0.5)  # округляяем вниз
        x = 1
        while True:
            q = (m + x) ** 2 - num
            if int(q ** 0.5) == q ** 0.5:
                b = int(q ** 0.5)
                a = m + x
                break
            else:
                x += 1
        d1 = a + b # находим делители по формуле 
        d2 = a - b 
    if d1 not in resheto(d1): # если делитель не простой то повторяем над ним алгоритм ферма
        divs.extend(ferm(d1)) # extend чтобы не получиласиь вложенные списки
    else:
        divs.append(d1) # если простой то добавляем сразу 
    if d2 not in resheto(d2): # анлогично со вторым делителем
        divs.extend(ferm(d2)) # extend чтобы не получиласиь вложенные списки
    else:
        divs.append(d2)
    return divs # возвращаем все наши  простые делители

for i in range(3):
    num = int(input("Введите число для факторизации: "))
    row = ferm(num) # алгоритм ферма
    row_s = set(row) # создаем множество из делителей
    s = '' # строка где будем получать факторизацию 
    for i in row_s:
        s += f'{i}^{row.count(i)} * ' # добавляем каждый множитель в степени в строку с факторизацией
    answer = s[:-3] # убираем ' * '
    print("Итоговая факторизация: ", answer)

