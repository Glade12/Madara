print("Введите число")
a=int(input())
i=2
p=0
while i<a:
    if (a % i==0):
        p=1
        i=a
if (p==0):
    print("Простое число")
else:
    print ("Составное число")
