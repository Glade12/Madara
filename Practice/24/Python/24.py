import json
from array import *
c=0#Переменная для записи кол-во правильно выполненых заданий
p=0#Элемент в списке
m=list('')#пустой список
x='a'
with open('in.json','r') as f:
    a=f.read()#Преобразуем в строку
    data=json.loads(a)#Преобразуем в список
    h=dict(data[0])#Выбираем первый элемент списка и обозначаем как словарь 
    k=h['userId']
    for l in range(len(data)):#Перебераем всем элементы заданного файла
        h=dict(data[l])
        if (k==h['userId']):#Сравниваем какой id
            if (h['completed']==1):#Находим правильно выполненные задания
                c+=1
        else:
            d={'userId':k,
                'task_completed':c
            }
            m.append(x)#Увеличиваем список по необходимости
            m[p]=d#Записываем в ячейки списка, словари содежащий userId и правльно выполненные заданния
            p+=1
            c=0
            k=h['userId']
            if (h['completed']==1):
                c+=1
    d={'userId':k,
        'task_completed':c
    }
    m.append(x)
    m[p]=d            
print(m)
with open ('out.json','w') as b:
    b=json.dump(m,b,indent=3)
  
    
        
    
