n  = int(input("Введите кол-во сигналов\n"))
signals = list(input("Введите сигналы \n").split())
raw = []
for i in range(n):
	if (i < 5):
		raw.append(signals[i])
	else:
		if (raw[0] > signals[i]):
			raw[0], signals[i] = signals[i], raw[0]
	raw.sort(reverse=True)
h = " ".join(raw)
print(h)				
