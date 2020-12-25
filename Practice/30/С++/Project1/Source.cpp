#include <iostream>
#include <string>
#include <map>
#include <vector>



template <class T>
using vector_t = std::vector<T>;

template <class T>
bool is_more(const T& first, const T& second)
{
	return first > second;
}

template <class T>
bool is_less(const T& first, const T& second)
{
	return first < second;
}

template <class T>
bool is_sorted(const vector_t<T>& vector, const bool& asc)
{
	const auto sort = asc ? is_more<T> : is_less<T>;

	for (size_t i = 1; i < vector.size(); ++i)
	{
		if (sort(vector[i - 1], vector[i]))
		{
			return false;
		}
	}

	return true;
}

template <class T>
vector_t<T> BozoSort(const vector_t<T>& vector, const bool& asc)
{
	vector_t<T> result = vector;
	if (vector.size() < 2)
	{
		return result;
	}

	const size_t size = result.size();
	while (!is_sorted(result, asc))
	{
		std::swap(result[std::rand() % size], result[std::rand() % size]);
	}
	return result;
}

struct Student {
	std::string name;
	int group;
	std::map <std::string, int> exams ;


Student(std::string name1, int group1, int mathematics1, int physics1, int history1, int  programming1) {
	name = name1;
	group = group1;
	exams = { {"mathematics", mathematics1}, {"physics", physics1}, {"history", history1}, {"programming", programming1} };
}
friend std::ostream& operator <<(std::ostream& stream, const Student& Student) 
{
	const auto Lenght = std::max(Student.name.length(), static_cast<size_t>(4));
	const std::string a(Lenght, '-');

	stream << "+-" << a << "-+-------+------+------+------+------+\n"
		<< "| Name " << std::string(Lenght - 4, ' ')
		<< "| Group | Math | Phys | Hist | Prog |\n"
		<< "|-" << a << "-+-------+------+------+------+------+\n"
		<< "| " << Student.name << " | " << Student.group
		<< "     | " << Student.exams.at("mathematics")
		<< "    | " << Student.exams.at("physics")
		<< "    | " << Student.exams.at("history")
		<< "    | " << Student.exams.at("programming")
		<< "    |\n"
		<< "+-" << a << "-+-------+------+------+------+------+\n";

	return stream;

}
bool operator <(const Student& other) const
{
	return name < other.name;
}

bool operator >(const Student& other) const
{
	return name > other.name;
}
};
std::ostream& operator <<(std::ostream& stream, const std::vector<Student>& students)
{
	auto Length = students.at(0).name.length();
	for (auto itr = students.begin() + 1; itr != students.end(); ++itr)
	{
		if (itr->name.length() > Length)
		{
			Length = itr->name.length();
		}
	}

	const std::string a(Length, '-');

	stream << "+-" << a << "-+-------+------+------+------+------+\n"
		<< "| Name " << std::string(Length - 4, ' ')
		<< "| Group | Math | Phys | Hist | Prog |\n"
		<< "+-" << a << "-+-------+------+------+------+------+";

	for (const auto& Student : students)
	{
		stream << "\n| " << Student.name
			<< std::string(Length - Student.name.length(), ' ')
			<< " | " << Student.group
			<< "     | " << Student.exams.at("mathematics")
			<< "    | " << Student.exams.at("physics")
			<< "    | " << Student.exams.at("history")
			<< "    | " << Student.exams.at("programming")
			<< "    |\n"
			<< "+-" << a << "-+-------+------+------+------+------+";
	}

	stream << std::endl;

	return stream;
};
int main(){
    std::vector<Student> students = BozoSort(std::vector<Student>{
       Student("Sakuragi H",   2, 4, 3, 2, 5),
       Student("Rukawa K",    5, 5, 3, 3, 5),
       Student("Miyagi R",      2, 2, 5, 2, 5),
       Student("Akagi T",   4, 5, 5, 4, 5),
       Student("Mitsui H",     4, 2, 2, 3, 5),
       Student("Sendo S",     2, 5, 5, 4, 5),
       Student("Maki S",         5, 2, 5, 3, 5),
       Student("Ayako S",       3, 4, 5, 3, 5),
       Student("Savakita B",     5, 2, 3, 4, 5),
       Student("Fudjima K",        5, 4, 3, 4, 5),
    },true);
	auto has_failed = [](Student& Student) -> bool {
		for (auto& pair : Student.exams)
		{
			if (pair.second == 2)
			{
				return true;
			}
		}
		return false;
	};

	
	std::vector<Student> failed;
	for (auto& student : students)
	{
		if (has_failed(student))
		{
			failed.push_back(student);
		}
	}
	if (failed.size() > 0)
	{
		std::cout << failed << std::endl;

		std::cout << "\nExplusion\n"
			<< failed.at(std::rand() % failed.size()) << std::endl;
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
}