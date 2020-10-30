from math import sqrt
print("Введите коэффиценты")
a=float(input())
b=float(input())
c=float(input())
if (a==0)and(b==0)and(c==0):
    print("Любой корень")
elif (a==0):
    if (c==0):
        print("Корень = 0")
    else:
        print("Корень =", -c/b)
elif (b==0):
    if (c==0):
        print("Корень = 0")
    else:
        print("Корень =", sqrt(-c/a))
elif (c==0):
    print("Первый корень = 0")
    print("Второй корень =", -b/a)

else:
    D=((b*b)-4*a*c)
    if (D<0):
        print("Нет корней")
    elif (D==0):
        print("Корень =", -b/(2*a))
    else:
        print ("Первый корень =", (-b+sqrt(D))/(2*a))
        print ("Второй корень =", (-b-sqrt(D))/(2*a))
