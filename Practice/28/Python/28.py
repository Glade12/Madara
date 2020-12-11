def print_factorization(n: int) -> None:
	cout = []
	a = dict()
	sol = 2
	while(n > 1):
		while (n % sol == 0):
			cout.append(sol)
			n = n/sol
		sol += 1
	f = 1
	s = len(cout)
	if(s > 1):
		while (f):
			i = 1
			while(1):
				if (s - i == 0):
					f = 0
					break	
				if (cout[i] == cout[i - 1]):
					if i-1 not  in  a:
						a[i - 1] = 2
					else:
						a[i - 1] += 1
					del cout[i]
					s = len(cout)
					break	
				i+=1
		for i in range (len(cout)):
			if i in a:
				if (a[i] > 0):
					cout[i] = str(str(cout[i]) + "^" + str(a[i]))
		for i in range(len(cout)):
			cout[i] = str(cout[i])
		k = '*'.join(cout)
	else:
		k = cout[0]
	return(k)
n = int(input("Введите\n"))
print(print_factorization(n))


	

