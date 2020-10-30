from math import fabs
print("Введите время прихода людей")
a,b=input().split(':')
e,r=input().split(':')
a=int(a)
b=int(b)
e=int(e)
r=int(r)
if(((fabs(r-b))<=15)or((fabs(b-r))<=15))and((fabs(a-e))<=1)or((fabs(e-a))<=1):
    print("Встреча состоиться")
else:
    print("Встреча не состоиться")
