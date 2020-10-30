print("Введите число")
n=int(input())
x=1
c=1
f=0
while(1):
    if (x<=n) and (c<=n):
        f+=1
        x+=1
        c=c*2
    else:
        break
print(f)
