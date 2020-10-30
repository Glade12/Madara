from math import fabs
print("Введите начальную координтау, скорость и время",'\n')
a=int(input())
b=int(input())
c=int(input())
g=9.8
print("Расстояние которое перодалел объект",fabs((a+b*c-(g*c*c)/2)-a))
