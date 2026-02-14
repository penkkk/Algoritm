def foo(a, b, p):
    return a - b*p

a = int(input())
b = int(input())
left_point = 0
right_point = a
while left_point < right_point:
    center = (left_point + right_point + 1) // 2
    if foo(a, b, center) >= 0:
        left_point = center
    else:
        right_point = center - 1

chastnoe = left_point
ostat = a - b*chastnoe
print("Частное: ", chastnoe)
print("Остаток: ", ostat)
