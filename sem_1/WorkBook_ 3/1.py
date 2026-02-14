from random import randint

def num_generation(n):
    return [randint(1,9)] + [randint(0,9) for i in range(n - 1)]

def check_value(value_1, value_2, n):
    for i in range(n):
        if value_1[i] > value_2[i]:
            mx = value_1
            mn = value_2
            break
        elif value_1[i] < value_2[i]:
            mx = value_2
            mn = value_1
            break
        else:
            mx = mn = value_1 = value_2
    return mx, mn

def addition(value_1, value_2, n):
    ans = [0 for i in range(n)]
    value_1, value_2 = value_1[::-1], value_2[::-1]
    a = 0
    for i in range(n):
        if value_1[i] + value_2[i] + a >= 10:
            ans[i] = (value_1[i] + value_2[i] + a) % 10
            a = (value_1[i] + value_2[i] + a) // 10
        else:
            ans[i] = value_1[i] + value_2[i] + a
            a = 0
    if a > 0:
        ans.append(a)
    if ans[::-1][0] != 0:
        return ans[::-1]
    else:
        return ans[::-1][1::]

def subtraction(mx, mn, n):
    ans = [0 for i in range(n)]
    mx, mn = mx[::-1], mn[::-1]
    for i in range(n):
        if mx[i] - mn[i] < 0:
            ans[i] = mx[i] + 10 - mn[i]
            mx[i + 1] -= 1
        else:
            ans[i] = mx[i] - mn[i]
    return ans[::-1]
    
n = int(input("Введите количество цифр в числе: "))
num_1 = num_generation(n)
num_2 = num_generation(n)
mx, mn = check_value(num_1, num_2, n)
print("Максимальное из сгенерированных чисел: ", mx)
print("Минимальное из сгенерированных чисел: ", mn)
print("Результат сложения: ", addition(num_1, num_2, n))
print("Результат вычитания(из большего меньшего): ", subtraction(num_1, num_2, n))
