def merson_test_luke(num):
    mersen = 2 ** num - 1 # получаем число мерсона по его номеру
    luke = [4] # создаем последовательность люка - лемера
    for i in range(1, num):
        s = luke[i-1] ** 2 - 2
        luke.append(s) # заполняем последовательность люка - лемера числами
    if luke[num - 2] % mersen == 0: # тест люка - лемера
        return 'Простое'
    else:
        return 'Составное'

for i in range(3):
    n = int(input('Введите номер числа Мерсонна: '))
    print(merson_test_luke(n))
