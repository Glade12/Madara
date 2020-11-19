#include <nlohmann/json.hpp>
#include<iostream>
#include<map>
#include<iomanip>
#include<fstream>

using namespace std;
using json = nlohmann::json;


int main() {
    std::map  <int, int> a;//Словарь в котором ключ=userId, значение=сколько правильных тестов
    std::ifstream i("in.json");
    json j;
    i >> j;
    for (int i = 0; i < j.size(); i++)
    {
        if (j[i]["completed"] == true)
        {
            a[j[i]["userId"]] += 1;
        }
    }
    json l = json::array();
    for (auto e : a)
    {
         l.push_back({ {"userId",e.first},{"task_completed",e.second} });
    }
    std::ofstream o("out.json");
    o << std::setw(3) << l << endl;
    return 0;
}