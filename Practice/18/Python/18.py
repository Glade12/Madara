import collections
a=dict(collections.Counter('halloklempnerdasistfantastischfluggegecheimen'))#словарь типа ключ-значение, вкоторый идет подсчет кол-во поторяющихся букв
print("Введите стоп слово",'\n',sep='')
c=str(input())
f=[0]*len(c)
b=str('halloklempnerdasistfantastischfluggegecheimen')
t=float(1)
k=0 #переменная отвечающая за знания букв Сигизмундом
for i in range(len(c)): # с помощью цикла сравниваем словарный запас Сигизмунда и стоп-слово
    for j in range(len(b)):
        if (c[i]==b[j]):
            f[i]=f[i]+1 # заполняем массив, чтоб выяснить знает ли Сигизмунд буквы в стоп-слове
for i in range(len(c)):
    if (f[i]==0):
        k=1 
if (k==1):
    print('Сигизмунд не знает букву')
else:
    for i in range(len(c)):
        t=t*(a[c[i]]/len(b))
    print("Вероятность равна=",t)
    
