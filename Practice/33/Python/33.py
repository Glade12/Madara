import builtins 

def create(a, b, c):
	quest = []
	quest.append(b)
	for i in range(0, a):
		y = int(quest[i] + c)
		quest.append(y)
	return quest
def sort(quest, a):
	for i in range(1, a):
		key = quest[i]
		j = i-1
		while j >=0 and key < quest[j]:
			quest[j+1] = quest[j]
			j -= 1
			quest[j+1] = key 
	return quest		
def print(quest, a):
	builtins.print("[",end = "")
	for i in range(a):
		if(i+1 == a):
			builtins.print(quest[i],  end="")
		else:
			builtins.print(quest[i],  end=",")
	builtins.print("]")
	quest.clear()
	
a = int(input("Введите длину массива, начальный член, шаг арифметической прогрессии\n"))
b = int(input())
c = int(input())
print(sort(create(a,b,c), a), a)
