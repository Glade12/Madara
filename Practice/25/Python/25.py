import random
import math 
c = float(input("Введите предел "))
s = list(input().split())
sqrt = int (math.sqrt(c))
cicle = int(c)
list_list = [[0]*sqrt for i in range(sqrt)]
nu=0
for i in range (sqrt):
        for j in range (sqrt):
                list_list[i][j] = s[nu]
                nu+=1
first = s[0]
second = s[1]
third = s[2]
def BozoSort(s,cicle, k = True):
        f = 1
        while(f):
                f = 0
                a = int(random.randint(0, (c-1)))
                b = int(random.randint(0, (c-1)))
                s[a], s[b] = s[b], s[a]
                for i in range (1,cicle):
                        if (k):
                                if s[i-1]>s[i]:
                                        f = 1
                                        break
                        else:
                                if s[i-1]<s[i]:
                                        f = 1
                                        break   
        k = " ".join(s)
        print(k)
BozoSort(s, cicle)
BozoSort(s, cicle, k = False)
def BozoSort(list_list, sqrt, k = True):
        f = 1
        while(f):
                f = 0
                a = int(random.randint(0, (sqrt-1)))
                b = int(random.randint(0, (sqrt-1)))
                ab = int(random.randint(0, (sqrt-1)))
                ba = int(random.randint(0, (sqrt-1)))
                list_list[a][ab], list_list[b][ba] = list_list[b][ba], list_list[a][ab]
                for i in range (sqrt):
                        for j in range (1,sqrt):
                        	if(k):
                        		if(j == 1 and i > 0):
                        			if list_list[i-1][sqrt - 1] > list_list[i][j - 1]:
                        				f = 1
                        				i = sqrt
                        				break
                        			else:
                        				if list_list[i][j - 1] > list_list[i][j]:
                        					f = 1
                        					i = sqrt
                        					break
                        		elif list_list[i][j - 1] > list_list[i][j]:
                        			f = 1
                        			i = sqrt
                        			break
                        	else:
                        		if(j == 1 and i > 0):
                        			if list_list[i-1][sqrt - 1] < list_list[i][j - 1]:
                        				f = 1
                        				i = sqrt
                        				break
                        			else:
                        				if list_list[i][j - 1] < list_list[i][j]:
                        					f = 1
                        					i = sqrt
                        					break
                        		elif list_list[i][j - 1] < list_list[i][j]:
                        			f = 1
                        			i =sqrt
                        			break                             
        for i in range (sqrt):
                for j in range (sqrt):
                        print(list_list[i][j], end = " ")
        print('')
BozoSort(list_list, sqrt)
BozoSort(list_list, sqrt,k = False)
def BozoSort(first, second, third,k = True):
        f = 1
        while(f):
                f = 0
                a = int(random.randint(2,4))
                if a == 2:
                        first, second = second, first
                elif a == 3:
                        second, third = third, second
                else:
                     first, third = third, first
                if(k):
                        if first > second:
                                f = 1
                        elif  second > third:
                                f = 1
                else:
                        if first < second:
                                f = 1
                        elif second < third:
                                f = 1
        print(first,second,third)
BozoSort(first, second, third)
BozoSort(first, second, third,k = False)


