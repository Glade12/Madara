print("Введите сумму и диапозоны чисел")
s,l1,r1,l2,r2= map(int,input().split(' '))
a=0
if s > (r1 + r2) | s < (l1 + l2):
    print (-1, end = '')
else:
    if (s - l1) >= l2:
        if s <= (l1 + r2):
            if (((s-l1)>=l2)and((s-11)<=r2)):
                print (l1, s - l1, end = '')
            else:
                print(-1,end = ' ')
        else: 
            a = abs (s - (l1 + r2))
            if (l1 + a) < r1 & (r2 - a) > l2:
                print (l1 + a, s - (l1 + a), end = '')
            else: 
                print (-1, end = '')            
    else:
        print (-1, end = '')
        
