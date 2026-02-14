import time
import random

def buble_sort(array):
    flag = 1
    while flag == 1:
        flag = 0
        for i in range(len(array) - 1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                flag = 1
    return array

 
def shaker_sort(array):
    flag = 1
    start = 0
    end = len(array) - 1
    step = 1
    while flag == 1:
        flag = 0
        swap = -1
        if step == 1:
            for i in range(start, end, step):
                if array[i] > array[i + 1]:
                    array[i], array[i + 1] = array[i + 1], array[i]
                    flag = 1
                    swap = i
            end = swap
        else:
            for i in range(end, start, step):
                if array[i] < array[i - 1]:
                    array[i], array[i - 1] = array[i - 1], array[i]
                    flag = 1
                    swap = i
            start = swap
        step *= -1
    return array


def inser_sort(array):
    for i in range(len(array)):
        current = array[i]
        for j in range(0, i):
            if current < array[j]:
                array.insert(j, current)
                array.pop(i + 1)
                break
    return array

def selection_sort(array):
    for i in range(len(array) - 1):
        min_index = i
        for j in range(i + 1, len(array)):
            if array[min_index] > array[j]:
                min_index = j
        if min_index != i:
            array[i], array[min_index] = array[min_index], array[i]         
    return array

def shell_sort(array):
    n = len(array)
    d = n // 2
    while d > 0:
        for i in range(d, n):
            current = array[i]
            j = i
            while (j >= d) and array[j - d] > current:
                array[j] = array[j - d]
                j -= d
            array[j] = current
        d //= 2
    return array

def quick_sort_main(array):
    def separation(array, left, right):
        supporting = array[right]
        i = left - 1
        for j in range(left, right):
            if array[j] < supporting:
                i += 1
                array[i], array[j] = array[j], array[i]
        array[i + 1], array[right] = array[right], array[i + 1]
        return i + 1

    def quick_sort(array, left, right):
        if left < right:
            indx = separation(array, left, right)
            quick_sort(array, left, indx - 1)
            quick_sort(array, indx + 1, right)
    
    quick_sort(array, 0, len(array) - 1)
    return array

def time_meter(sort_foo, array, name): # функция замера времени
    arr_copy = array.copy()  #копируем исходный массив чтобы сортировать всегда исходный массив
    start = time.perf_counter() # perf_counter() для точного измерения времени, замеряем начало
    result = sort_foo(arr_copy) # прогоняем сортировку
    finish = time.perf_counter() # замеряем конец 
    total_time = finish - start # затраченное время
    print(f"{name}: {total_time:.8f} секунд") # вывод названия сортировки и время с округлением до 8 знаков после запятой

small_array = [37, 5, 88, 14, 62, 9, 31, 70, 1, 47]
big_array = [random.randint(1, 10000) for j in range(1000)]

print("For small array:")
time_meter(buble_sort, small_array, "Пузырьковая сортировка")
time_meter(shaker_sort, small_array, "Шейкерная сортировка")
time_meter(inser_sort, small_array, "Сортировка вставками")
time_meter(selection_sort, small_array, "Сортировка выбором")
time_meter(shell_sort, small_array, "Сортировка Шелла")
time_meter(quick_sort_main, small_array, "Быстрая сортировка")

print("---------------------------------------------")

print("For big array")

time_meter(buble_sort, big_array, "Пузырьковая сортировка")
time_meter(shaker_sort, big_array, "Шейкерная сортировка")
time_meter(inser_sort, big_array, "Сортировка вставками")
time_meter(selection_sort, big_array, "Сортировка выбором")
time_meter(shell_sort, big_array, "Сортировка Шелла")
time_meter(quick_sort_main, big_array, "Быстрая сортировка")

#For small array:
# Пузырьковая сортировка: 0.00001580 секунд
# Шейкерная сортировка: 0.00001070 секунд
# Сортировка вставками: 0.00001100 секунд
# Сортировка выбором: 0.00000880 секунд
# Сортировка Шелла: 0.00001030 секунд
# Быстрая сортировка: 0.00001710 секунд
# ---------------------------------------------
# For big array
# Пузырьковая сортировка: 0.14711010 секунд
# Шейкерная сортировка: 0.08583240 секунд
# Сортировка вставками: 0.01073370 секунд
# Сортировка выбором: 0.04366290 секунд
# Сортировка Шелла: 0.00297500 секунд
# Быстрая сортировка: 0.00168490 секунд
