#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
struct Person
{
	int UserId;
	int task_completed;
};

int main()
{	
	Person d{1,10};
	json f{};
	f["UserId"] = d.UserId;
	f["task_completed"] = d.task_completed;
	cout << f;
}