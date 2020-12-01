import random
c = int(input("Введите предел "))
s = list(input().split())
f = 1
while(f):
	f = 0
	a = int(random.randint(0, (c-1)))
	b = int(random.randint(0, (c-1)))
	s[a], s[b] = s[b], s[a]
	for i in range (1,c):
		if s[i-1]>s[i]:
			f = 1
			break;
k = " ".join(s)
print(k)
	
    
