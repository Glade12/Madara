print("Введите количество банкнот")
n = int(input())
m = 0
k = 0
f = str
print("Введите банкноты ")# к сожалению не получилось сделать ввод через пробел
while k < n:
    
    a =input()
    if a[0] == 'a' and a[4] == '5' and a[5] == '5' and a[6] == '6' and a[7] == '6' and a[8] == '1':
        f= a + ' '
    else:
        m = m + 1
    k = k + 1
if m == n:
    print("-1")
else:
    print(f)
