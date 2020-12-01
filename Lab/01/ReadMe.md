<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 1<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ПИ-б-о-201(2)<br>
Долгий Сергей Григорьевич<br>
направления подготовки 09.03.04 "Программная инженерия"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>
<h3> Цель работы:</h3><br>
1.Закрепить навыки разработки многофайловыx приложений;<br>
2.Изучить способы работы с API web-сервиса;<br>
3.Изучить процесс сериализации/десериализации данных в/из json;<br>
4.Получить базовое представление о сетевом взаимодействии приложений;<br>
<h3> Постановка задачи</h3><br>
Разработать сервис предоставляющий данные о погоде в городе Симферополе на момент запроса.  В качестве источника данных о погоде используйте:
http://openweathermap.org. В состав сервиса входит: серверное приложение на языке С++ и клиентское приложение на языке Python.<br>
Серверное приложение (далее Сервер) предназначенное для обслуживания клиентских приложений и минимизации количества запросов к сервису openweathermap.org. Сервер должен обеспечивать возможность получения данных в формате JSON и виде html виджета (для вставки виджета на страницу будет использоваться iframe).<br>
Клиентское приложение должно иметь графический интерфейс отображающий сведения о погоде и возможность обновления данных по требованию пользователя.<br>
<h3> Ход работы:</h3><br>

Для начала необходимо получить  API ключ на сайте http://openweathermap.org. Ключ(default):b36d9d82ce4cc2359da6879016f3f61f. Также получаем дополнительные ключи для закрепления.<br>
![](./images/ApiKeys.png)
<p align="center">Рис.1 Полученные ключи<br></p>
После полученния Api ключа, проводим наш первый запрос и узнаем состояние погоды города Сиферополь на ближайшие два дня(по часам).Запрос:http://api.openweathermap.org/data/2.5/onecalllat=44.5653&lon=34.0615&lang=ru&units=metric&exclude=current,minutely,daily,alerts&appid=b36d9d82ce4cc2359da6879016f3f61f

![](./images/ApiOpenWeatyher.png)
<p align="center">Рис.2 Запрос на http://api.openweathermap.org <br></p>
Дальше используем сервис http://worldtimeapi.org для того, чтобы узнать точное время. Для этого проводим запрос http://worldtimeapi.org/api/timezone/Europe/Simferopol.

![](./images/WorsTimeApi.png)
<p align="center">Рис.3 Запрос на http://worldtimeapi.org <br></p>

  После изучения предложенного материала,переходим к разработке серверного приложения (далее Сервер). Сервер состоит из трех функций, так как Сервер должен уметь отвечать на два запроса "/"(Отве в виде виджета), а также "/raw"(Ответ в формате JSON). Первая функция отвечает на запрос "/",  в теле функции прописываем два get запроса, на сервисы  http://worldtimeapi.org и http://api.openweathermap.org. Затем проверяем на ошибки. Наша задача сравнить время указанное  в ответах. Так как оба ответа представлены в фомате JSON, то мы парсим тела ответов в переменные JSON.(Заранее подключили все необходимые библиотеки, указанные в лабораторной работе.) Обращаемся к ключам(в нашем случае это ["hourly"][i]["dt] и ["unixtime]) и сравгиваем их, чтобы узнать, не устарели ли наи данные. После проверки переходим к к открытию заранее скаченного шаблона виджета. Считываем его в новую переменную, указываем тип string. Переходи к поиску и замене параметров, отвечающие за температуру и состояние погоды. Для этого используем функции find и replace. Заменяем строчки {hourly[i].weather[0].description}, {hourly[i].weather[0].icon}, {hourly[i].temp}, на значения из заранее полученного ответа JSON фотмата, по ключам(заменяемые строчки имееют названее ключей). Затем преобразуем числовые типы данных, в типы string, с помощью функции to_string. С помощью set_content, передаеи в ответ ввиде пеменной, где мы и производили описанные выше действия, в формате text/html. Следующая функция отвечает на зарос "/raw". Там иы также проводим запросы на сервисы, парсим ответы и проверяем устаревшие данные. Отличее от первой функции заключает в формате ответа, где Сервер должен выдать JSON. Для этого отбъявляем новый json и инициализируем в нем два ключа: "Temperature" и "description_12". В них передаем значения из полученного JSONа. В ответ на запрос передаем новый json. И основная функция main, служит для запуска Сервера.
~~~C++
#include <iostream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <math.h>
using namespace httplib;
using json = nlohmann::json;

void gen_response1(const Request& req, Response& res){
    Client cli("http://worldtimeapi.org");
    auto clientTime = cli.Get("/api/timezone/Europe/Simferopol");
    Client cli1("http://api.openweathermap.org");
    auto clientWeather = cli1.Get("/data/2.5/onecall?lat=44.5653&lon=34.0615&lang=ru&units=metric&exclude=current,minutely,daily,alerts&appid=b36d9d82ce4cc2359da6879016f3f61f");
    if (clientTime)                       {
        int error = clientTime->status;
        if (clientTime->status == 200) {

            json time = json::parse(clientTime->body);
            json weather = json::parse(clientWeather->body);
            for (int i = 0; i < 48; i++) {

                if (weather["hourly"][i]["dt"].get<ULONG64>() > time["unixtime"].get<ULONG64>()) {
                    std::ifstream file("123.txt");
                    std::string text;
                    getline(file, text, '\0');
                    file.close();
                    std::string first = "{hourly[i].weather[0].description}";
                    std::string second = "{hourly[i].weather[0].icon}";
                    std::string third = "{hourly[i].temp}";
                    text.replace(text.find(first), first.size(), weather["hourly"][i]["weather"][0]["description"]);
                    text.replace(text.find(second), second.size(),weather["hourly"][i]["weather"][0]["icon"]);
                    text.replace(text.find(third), third.size(), std::to_string(int(round(weather["hourly"][i]["temp"].get<double>()))));
                    text.replace(text.find(third), third.size(), std::to_string(int(round(weather["hourly"][i]["temp"].get<double>()))));
                    res.set_content(text, "text/html;  charset=UTF-8");
                    break;
                }
            }
            
        
        }
      else{
        
            res.set_content(std::to_string(error), "text/plain");
        }
    }
    else  res.set_content("errorq", "text/plain");
   

}  
void gen_response(const Request& req, Response& res)
{
    Client cli("http://worldtimeapi.org");
    auto clientTime = cli.Get("/api/timezone/Europe/Simferopol");
    Client cli1("http://api.openweathermap.org");
    auto clientWeather = cli1.Get("/data/2.5/onecall?lat=44.5653&lon=34.0615&lang=ru&units=metric&exclude=current,minutely,daily,alerts&appid=b36d9d82ce4cc2359da6879016f3f61f");
    if (clientTime) {
        int error = clientTime->status;
        if (clientTime->status == 200) {

            json time = json::parse(clientTime->body);
            json weather = json::parse(clientWeather->body);
            for (int i = 0; i < 48; i++) {

                if (weather["hourly"][i]["dt"].get<ULONG64>() > time["unixtime"].get<ULONG64>()) {
                    json new12;
                    new12["Temperature"] = std::to_string(int(round(weather["hourly"][i]["temp"].get<double>())));
                    new12["description_12"] = weather["hourly"][i]["weather"][0]["description"];
                    std::string output = new12.dump(4);
                    res.set_content(output, "text/json");

                    break;
                }
            }


        }
        else {

            res.set_content(std::to_string(error), "text/plain");
        }
    }
    else  res.set_content("errorq", "text/plain");
}
    int main()
    {
        Server svr;
        svr.Get("/", gen_response1);
        svr.Get("/raw", gen_response);
        std::cout << "Start server... OK\n";
        svr.listen("localhost", 3000);
    }
~~~
![](./images/Vidget.png)
<p align="center">Рис.4 Виджет <br></p>

  После изучения предоставленного материала переходим к разработке клиентского приложения(далее КП). По условию задания КП должно иметь графический интресфейс,шаблон предоставлен в задании. Созданем три поля с помощью команд Label. В первом содержиться название города и состояния погоды. Название города можно указать в ручную, а вот состояние погоды мы будем получать с ранее созданного серверного приложения(далее Сервера). Запрос будет оканчиваться на "/raw", поэтому ответ будет в JSON формате(все необходимые библиотеки подключены заранее). В первое поле будет идти значение от ключа "description_12",которое и отвечает за состояние погоды,записваем его в отдельную переменную и меняем тип на string.Здесь полученные данные выводятся в неправильной кодировке, поэтому воспользуемся командой "тут корявый текст".encode('l1').decode()". Во втором поле указывается температура. Используем значение от ключа "Temperature", а также прописываем "°C". Для оформления пользуемся командой grind, которая оформляет наш КП, как таблицу со строчками и столбцами. Для взаимодействия пользователя и КП используем команду команду bind. Функция записанная в эту команду, вызвает повторный запрос на сервер и обновляет данные.
  
![](./images/Client.png)<br>
Рис.5 Готовое КП<br>
~~~Python
from tkinter import *
from json import *
import requests
def font1(event):
	r = requests.get('http://localhost:3000/raw')
	p = r.json()
	f = str(p["description_12"])
	f = f.encode('l1').decode()



r = requests.get('http://localhost:3000/raw')
p = r.json()
f = str(p["description_12"])
f = f.encode('l1').decode()


root = Tk()
root.title("天気")

City = Label(root, width = 17, text = "Симферополь",  font= "Arial 12", bg="orange")
Description = Label(root, width = 25, height = 1, text = (f), font= " Arial 8", bg="orange")
Temp = Label(root, text =(p["Temperature"],"°C"), height = 2 , font = "Arial 30")
Bottom = Label(root, width = 22,height = 2, bg = "orange")


City.grid(row=0,column=0)
Description.grid(row=1,column=0)
Temp.grid(row=2,column=0)
Bottom.grid(row=3,column=0)
City.bind('<Button-3>', font1 )
Description.bind('<Button-3>', font1)
Temp.bind('<Button-3>', font1)
Bottom.bind('<Button-3>', font1)
root.mainloop()
~~~
<h3>Вывод</h3><br>
В ходе проведения лабораторной работы, было разработано клиент-серверное приложение(далее КСП). Для написания КСП предварительно были изучены библиотеки С++: json и cpp-httplib(и скачаны с указанных ссылок), у Python были изучены: json и Tkinter. Были выработаны базовые навыки создания get запросов, обработки JSON объектов и создания графических интерфейсов. Также были закреплены базовые навыки разработки многофайловых приложений.

<h3>Каталоги</h3><br>

[C++](./C++) [Python](./Python) [images](./images)
