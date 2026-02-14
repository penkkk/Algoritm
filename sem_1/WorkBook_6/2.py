def foo(s):
    res = dict()
    for i in s:
        if i not in res:
            res[i] = 1
        else:
            res[i] += 1
    return res

print(foo('sdasoidsji'))
