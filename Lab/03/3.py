from tkinter import *
from PIL import Image, ImageTk
import random

root = Tk()
  
root.title("スティールボールラン")
root["bg"] = "gray22"


bb = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/0.png").convert('RGBA')).crop((1, 0, 55, 55)))
bdb = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/1.png").convert('RGBA')).crop((1, 0, 55, 55)))
bgr = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/2.png").convert('RGBA')).crop((1, 0, 55, 55)))
bp = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/3.png").convert('RGBA')).crop((1, 0, 55, 55)))
bo = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/4.png").convert('RGBA')).crop((1, 0, 55, 55)))
bpu = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/5.png").convert('RGBA')).crop((1, 0, 55, 55)))
by = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/6.png").convert('RGBA')).crop((1, 0, 55, 55)))
bb1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/0.png").convert('RGBA')).crop((17, 320, 39, 336)))
bdb1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/1.png").convert('RGBA')).crop((17, 320, 39, 336)))
bgr1= ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/2.png").convert('RGBA')).crop((17, 320, 39, 336)))
bp1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/3.png").convert('RGBA')).crop((17, 320, 39, 336)))
bo1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/4.png").convert('RGBA')).crop((17, 320, 39, 336)))
bpu1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/5.png").convert('RGBA')).crop((17, 320, 39, 336)))
by1 = ImageTk.PhotoImage((Image.open("C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/6.png").convert('RGBA')).crop((17, 320, 39, 336)))
path = "C:/Users/Сергей/Desktop/Programming/Lab/03/pictures/1.jpg"

which_balls = [bb, bdb, by]
if_ball = [[0] * 9 for i in range(9)] 
clck_ball = []
kinds = [1, 2, 7]
balls = [1, 2, 3]
#remember_pos = [[0] * 5 for i in range (5) ]
kind_of_balls = [[0] * 9 for i in range(9)]
remember_pos = []
score = [0]

def scores():
	counter = 0
	for i in range(9):
		for j in range(9):
			if if_ball[i][j] == 1:
				counter += 1
				k = j + 1
				while(1):
					if (k < 9):
						if (kind_of_balls[i][j] == kind_of_balls[i][k]):
							counter += 1
							if (counter == 5):
								if(k == 9):
									k-= 1
								while(k >= j):
									a = Label(root, image = image, bg = "gray22")
									a.row = i
									a.col = k
									a.bind("<Button - 1>", pl)
									a.grid(row = i, column = k)
									if_ball[i][k] = 0
									kind_of_balls[i][k] = 0
									k -= 1
									score[0] = score[0] + 2
								i = 10
								j = 10
								counter = 1
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								break
							k = k + 1
						else:
							break			

					else:
						break
				k = j - 1
				while(1):
					if (k >= 0):
						if (kind_of_balls[i][j] == kind_of_balls[i][k]):
							counter += 1
							if (counter == 5):
								if(k == -1):
									k += 1
								while(k <= j):
									a = Label(root, image = image, bg = "gray22")
									a.row = i
									a.col = k
									a.bind("<Button - 1>", pl)
									a.grid(row = i, column = k)
									if_ball[i][k] = 0
									kind_of_balls[i][k] = 0
									score[0] = score[0] + 2
									k += 1
								i = 10
								j = 10
								counter = 1
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								break
							k = k - 1
						else:
							counter = 0
							break
					else:
						counter = 0
						break
	counter = 0
	for i in range(9):
		for j in range(9):
			if if_ball[i][j] == 1:
				counter += 1			
				f = i + 1
				while(1):
					if (f < 9):
						if (kind_of_balls[i][j] == kind_of_balls[f][j]):
							counter += 1
							if (counter == 5):
								if(f == 9):
									f-= 1
								while(f >= i):
									a = Label(root, image = image, bg = "gray22")
									a.row = f
									a.col = j
									a.bind("<Button - 1>", pl)
									a.grid(row = f, column = j)
									if_ball[f][j] = 0
									kind_of_balls[f][j] = 0
									score[0] = score[0] + 2
									f -= 1
								i = 10
								j = 10
								counter = 1
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								break
							f = f + 1	
						else:
							break			

					else:
						break
				f = i - 1
				while(1):
					if (f >= 0):
						if (kind_of_balls[i][j] == kind_of_balls[f][j]):
							counter += 1
							if (counter == 5):
								if(f == -1):
									f += 1
								while(f <= i):
									a = Label(root, image = image, bg = "gray22")
									a.row = f
									a.col = j
									a.bind("<Button - 1>", pl)
									a.grid(row = f, column = j)
									if_ball[f][j] = 0
									kind_of_balls[f][j] = 0
									score[0] = score[0] + 2
									f += 1
								i = 10
								j = 10
								counter = 1
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								break
							f = f - 1
						else:
							counter = 0
							break
					else:
						counter = 0
						break
	counter = 0
	for i in range(9):
		for j in range(9):
			if if_ball[i][j] == 1:
				counter += 1			
				ro = i - 1
				co = j - 1
				while(1):
					if ((ro > -1) and (co > - 1)):
						if (kind_of_balls[i][j] == kind_of_balls[ro][co]):
							counter += 1
							if (counter == 5):
								if(ro == -1):
									ro += 1
								if(co == -1):
									co += 1
								while((ro <= i) and co <= j) :
									a = Label(root, image = image, bg = "gray22")
									a.row = ro
									a.col = co
									a.bind("<Button - 1>", pl)
									a.grid(row = ro, column = co)
									if_ball[ro][co] = 0
									kind_of_balls[ro][co] = 0
									co += 1
									ro += 1
									score[0] = score[0] + 2
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								i = 10
								j = 10
								counter = 1
								break
							ro = ro - 1
							co = co - 1
						else:
							break			

					else:
						break
				r = i + 1
				c = j + 1
				while(1):
					if ((r < 9) and (c < 9)):
						if (kind_of_balls[i][j] == kind_of_balls[r][c]):
							counter += 1
							if (counter == 5):
								if(r == 9):
									r -= 1
								if( c == 9):
									c -= 1
								while((r >= i) and (c >= j)):
									a = Label(root, image = image, bg = "gray22")
									a.row = r
									a.col = c
									a.bind("<Button - 1>", pl)
									a.grid(row = r, column = c)
									if_ball[r][c] = 0
									kind_of_balls[r][c] = 0
									score[0] = score[0] + 2
									r -= 1
									c -= 1
								i = 10
								j = 10
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								counter = 1
								break
							r = r + 1
							c = c + 1
							
						else:
							counter = 0
							break
					else:
						counter = 0
						break
	counter = 0
	for i in range(9):
		for j in range(9):
			if if_ball[i][j] == 1:
				counter += 1			
				ro = i - 1
				co = j + 1
				while(1):
					if ((ro > -1) and (co < 9 )):
						if (kind_of_balls[i][j] == kind_of_balls[ro][co]):
							counter += 1
							if (counter == 5):
								score[0] = score[0] + 10
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								if(ro == -1):
									ro += 1
								if(co == 9):
									co -= 1
								while((ro <= i) and co >= j) :
									a = Label(root, image = image, bg = "gray22")
									a.row = ro
									a.col = co
									a.bind("<Button - 1>", pl)
									a.grid(row = ro, column = co)
									if_ball[ro][co] = 0
									kind_of_balls[ro][co] = 0
									co -= 1
									ro += 1
								i = 10
								j = 10
								counter = 1
								break
							ro = ro - 1
							co = co + 1
						else:
							break			

					else:
						break
				r = i + 1
				c = j - 1
				while(1):
					if ((r < 9) and (c > -1)):
						if (kind_of_balls[i][j] == kind_of_balls[r][c]):
							counter += 1
							if (counter == 5):
								if(r == 9):
									r -= 1
								if( c == -1):
									c += 1
								while((r >= i) and (c <= j)):
									a = Label(root, image = image, bg = "gray22")
									a.row = r
									a.col = c
									a.bind("<Button - 1>", pl)
									a.grid(row = r, column = c)
									if_ball[r][c] = 0
									kind_of_balls[r][c] = 0
									score[0] = score[0] + 2
									r -= 1
									c += 1
								score_lbl = Label( text = " ".join((str("Счёт :"), str(score[0]))), font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
								score_lbl.grid(row = 0, column = 10)
								i = 10
								j = 10
								counter = 1
								break
							r = r + 1
							c = c - 1
						else:
							counter = 0
							break
					else:
						counter = 0
						break
	if(counter == 0):
		random_balls()
	counter = 0	
	return



def random_balls(): # Функция создания подсказки и заполнения шаров
	x = 630
	for i in range(3):
		ranr = random.randint(0, 8)
		ranc = random.randint(0, 8)
		while(1):
			counter = 0
			for g in range(9):
				for k in range(9):
					if (if_ball[g][k] == 0):
						break
					else:
						counter += 1
			if counter == 81:
				loss = Label(root, text = "Вы проиграли!",font = "Arial 12", fg = "white", bg = "gray22")
				loss.place(x = 630, y = 350)
				root.bind('<Button - 1>', new_game)
				i = 4
				break
			if (if_ball[ranr][ranc] == 0):
				ball = Label(root, image = which_balls[i], bg = "gray40")
				ball.bind('<Button - 1>', clc_ball)
				ball.row = ranr
				ball.col = ranc
				ball.kind = which_balls[i]
				ball.grid( row = ranr, column = ranc)
				if_ball[ranr][ranc] = 1
				kind_of_balls[ranr][ranc] = kinds[i]
				clck_ball.append(ball)
				break
			else:
				ranr = random.randint(0, 8)
				ranc = random.randint(0, 8)
	which_balls.clear()
	kinds.clear()
	for i in range(3):	
		rb = random.randint(0, 6)
		if (rb == 0):
			ball = Label(root, image = bb1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bb)
		elif(rb == 1):
			ball = Label(root, image = bdb1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bdb)
		elif(rb == 2):
			ball = Label(root, image = bgr1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bgr)
		elif(rb == 3):
			ball = Label(root, image = bp1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bp)
		elif(rb == 4):
			ball = Label(root, image = bo1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bo)
		elif(rb == 5):
			ball = Label(root, image = bpu1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(bpu)
		elif(rb == 6):
			ball = Label(root, image = by1, bg = "gray22")
			ball.place(x = x, y = 210)
			which_balls.append(by)
		x = x + 40
		kinds.append(rb + 1)

def new_game():
	for row in range(9):
		for col in range(9):
			a = Label(root, image = image, bg = "gray22")
			a.row = row
			a.col = col
			a.bind("<Button - 1>", pl)
			a.grid(row = row, column = col)
			if_ball[row][col] = 0
			kind_of_balls[row][col] = 0
			score[0] = 0
			score_lbl = Label( text = "Счёт : 0 ", font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
			score_lbl.grid(row = 0, column = 10)
	b = Label(bg = "gray22", borderwidth = 60)
	b.place( x = 630, y = 350)
	random_balls()
	
	
def clc_ball(event):
	event.widget.config(bg = "gray51")
	balls[0] = event.widget.row
	balls[1] = event.widget.col
	balls[2] = event.widget.kind
	
def pl(event):
	if (if_ball[event.widget.row][event.widget.col] == 0):
		if(balls[0] < 10) and (balls[1] < 10):
			change = Label(root, image = balls[2], bg ="gray40")
			change.bind('<Button - 1>', clc_ball)
			change.row = event.widget.row
			change.col = event.widget.col
			change.kind = balls[2]
			change.grid(row = event.widget.row, column = event.widget.col)
			if_ball[event.widget.row][event.widget.col] = 1
			kind_of_balls[event.widget.row][event.widget.col] = kind_of_balls[balls[0]][balls[1]]
			if_ball[balls[0]][balls[1]] = 0
			kind_of_balls[balls[0]][balls[1]] = 0
			bgrt = Label(root, image =  image, bg = "gray22")
			bgrt.row = balls[0]
			bgrt.col = balls[1]
			bgrt.grid(row = balls[0], column = balls[1])
			bgrt.bind('<Button - 1>', pl)
			scores()

	return()
		

image = ImageTk.PhotoImage(Image.open(path)) #Заполнение полей
for row in range(9):
	for col in range(9):
		a = Label(root, image = image, bg = "gray22")
		a.row = row
		a.col = col
		a.bind('<Button - 1>', pl)
		a.grid(row = row, column = col)


score_lbl = Label( text = "Счёт : 0", font = "Arial 16", fg = "white",bg = "gray22") #Вывод статистических  данных 
score_lbl.grid(row = 0, column = 10)
assist = Label(text = "Подсказка :", font = "Arial 11", fg = "white",bg = "gray22")
assist.grid(row = 2, column = 10)


new_game = Button(text = "Новая игра", bg = "gray50",font = "Arial 15", fg = "white", command = new_game) #Основные кнопки
move = Button(text = "Сделать ход", bg = "gray50",font = "Arial 11", fg = "white", command = random_balls)
move.grid(row = 1, column = 10)
new_game.grid(row = 4, column = 10)

random_balls()

root.mainloop()