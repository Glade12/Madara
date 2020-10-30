print("Введите значения")
a=input()
b=input()
c=a
a=b
b=c
print(a,'\n', b,'\n',sep='')
print("Возвращаем значения и проделываем без 3 переменной")
c=a
a=b
b=c
print(a,'\n', b,'\n',sep='')
a,b=b,a
print(a,'\n', b,'\n',sep='')
