import random
print("Попрубй угадать число!")
a=1
p=random.randint(1,100)
while(1):  
    b=int(input())
    if (a==5):
        if (b==p):
            print("Поздравляю! Вы угадали",'\n',"Хотите начать сначала? (1 - ДА )")
            с=int(input())
            if (с==1):
                p=random.randint(1,100)
                a=1
                b=int(input())
            else:
                break
        else:
            print("Вы проиграли. Было загадано:",p,'\n',"Хотите начать сначала? (1 - ДА )")
            с=int(input())
            if (с==1):
                p=random.randint(1,100)
                a=1
                b=int(input())
            else:
                break

    if (b==p):
        print("Поздравляю! Вы угадали",'\n',"Хотите начать сначала? (1 - ДА )")
        с=int(input())
        if (с==1):
            a=1
            p=random.randint(1,100)
        else:
            break
    elif (b>p):
        print("Загаданное число меньше")
    else:
        print("Загаданное число больше")
    a+=1
            
