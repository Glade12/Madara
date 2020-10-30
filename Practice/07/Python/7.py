from math import  sqrt 
f = int(input("Введите 1 для подсчета площади с помощью длин сторон или 2 для метода координат: "))            

if (f == 1):
    print("Введите стороны")
    a = int(input())
    b = int(input())
    c = int(input())
    if ((a < b + c) and (b < a + c) and (c < a + b)):
        p = (a + b + c) / 2
        S = sqrt(p * (p - a) * (p - b) * (p - c))
        print("S = ", S)
    else:
        print("Такой треугольник не  существует!")
elif (f == 2):
    print("Введите координаты, сначала по оси x, затем по оси y)
    x1 = int(input())
    y1 = int(input())
    x2 = int(input())
    y2 = int(input())
    x3 = int(input())
    y3 = int(input())
    a = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)))
    b = sqrt(((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)))
    c = sqrt(((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1)))
    if ((a < b + c) & (b < a + c) & (c < a + b)):
        p = (a + b + c) / 2
        S = sqrt(p * (p - a) * (p - b) * (p - c))
        print("S = ", S)
    else:
        print("Такой треугольник не может существовать!")
else:
     print("Ошибочный ввод")   
