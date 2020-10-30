print ("Введите число и степень")
a = float(input())
b = int(input())
p=1
if(b==0):
    print("1")
elif (a<0):
    a=-a
    for number in range(b):
        p=-1*a*p
    print(p)
elif (a==0):
    print("0")
else:
    for number in range(b):
        p=a*p
    print(p)
        
        
    
    
