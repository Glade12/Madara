
from array import *
b=0
c=0
j=0
f=[0]*37
for i in range (37):
    f[j]=i-1
    j+=1
j=0
for number in range(12):
    a=int(input())
    print(type(a))
    if (a < 0):
        break
    if (a==2):
        b=b+1
    elif (a==4):
        b=b+1
    elif (a==6):
        b=b+1
    elif (a==8):
        b=b+1
    elif (a==10):
        b=b+1    
    elif (a==11):
        b=b+1
    elif (a==13):
        b=b+1
    elif (a==15):
        b=b+1
    elif (a==17):
        b=b+1
    elif (a==20):
        b=b+1
    elif (a==22):
        b=b+1
    elif (a==24):
        b=b+1
    elif (a==26):
        b=b+1
    elif (a==28):
        b=b+1
    elif (a==29):
        b=b+1
    elif (a==31):
        b=b+1
    elif (a==33):
        b=b+1
    elif (a==35):
        b=b+1
    else:
        c=c+1
    for i in range (37):
        if (a==f[j]):
            f[j]=-1
            j+=1
    j=0
    for i in range (37):
         if (f[j]>=0):
            print(f[j]," ")
            j+=1
    j=0
    
    
    






















        
