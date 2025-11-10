def resheto(num):
    simple_numbers = [i for i in range(2, num + 1)] # массив чисел от 2 до num
    prime_index = 0
    while prime_index < len(simple_numbers):
        p = simple_numbers[prime_index] #берем простой элемент
        simple_numbers = [i for i in simple_numbers if i == p or i % p != 0] #оставляем подходяищие эл-ты
        # оставляем в этом массиве только числа которые не делятся на p
        prime_index += 1 # увеличивая индекс берем следующе p и проделываем ту же операцию 
    return simple_numbers

def fuctr(num):
    s = '' #строка куда будем записывать результат
    simple_numbers = resheto(num) # создаем список простых чисел до num импользуя решето эратосфена
    for i in simple_numbers: #организовываем перебор
        c = 0
        while num % i == 0: # считаем количество вхождений i в num
            num //= i
            c += 1
        if c > 0:
            s += str(i) + '^' + str(c) + ' * ' # получаем строку факторизации
    return s[:-3] # возвращаем строку факторизации без ' * ' на конце
n = int(input("Введите число для факторизаци:"))
print("Итоговая факторизация: ", fuctr(n))

