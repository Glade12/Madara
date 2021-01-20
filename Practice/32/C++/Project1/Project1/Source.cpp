#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


struct Passenger {
	std::string survival;        
	std::string pclass;          						
	std::string name;					
	std::string sex;						
	std::string age;			
	double age_double;
	std::string sibsp;           
	std::string parch;           
	std::string ticket;					
    std::string fare;        
	std::string cabin;					
	std::string embarked;				
};

std::string Comma(std::string& xi, int& p) {
	std::string avc = {};
	while (p < xi.length()) {
		if ((xi[p] == '\r') || (xi[p] == '\n') || (xi[p] == ',')) {
			break;
		}
		avc += xi[p];
		p++;
	}
	return avc;
}

std::string Q(std::string& qu, int& p) {
	std::string avc = {};
	bool Open = 1;
	while (p < qu.length()) {
		if ((qu[p] == '"')) {
			Open = !Open;
		}
		if ((qu[p] == '\r') || (qu[p] == '\n')) {
			break;
		}
		if ((qu[p] == ',') && (!Open)) {
			break;
		}
		if (Open)
			avc += qu[p];
		p++;
	}
	return avc;
}

int Skip(std::string& space, int p) {
	while (p < space.length()) {
		if ((space[p] == ' ') || (space[p] == '\t')) {
			p++;
		}
		else {
			return p;
		}
	}
	return -1;
}





void Read(std::string& x, std::vector<std::string>& v, int& p) {
	p = Skip(x, p);
	if (p > -1) {
		if (x[p] == '"') {
			p++;
			std::string a = Q(x, p);
			v.push_back(a);
		}
		else {
			std::string a = Comma(x, p);
			v.push_back(a);
		}
		if (x[p] == ',') {
			p++;
			Read(x, v, p);
		}
		else {
			p++;
		}
	}
}

std::istream& operator>>(std::istream& i, std::vector<Passenger>& p) {
	std::stringstream ss;
	ss << i.rdbuf();
	std::string l = ss.str();
	int posi = 0;
	int counter = 0;
	while (posi < l.length()) {
		counter++;
		std::vector<std::string> v = {};
		Read(l, v, posi);
		if (counter == 1) continue;
		Passenger s;
		s.survival = v[1];
		s.pclass = v[2];
		s.name = v[3];
		s.sex = v[4];
		s.age = v[5];
		try { s.age_double = std::stod(s.age); }
		catch (...) { s.age_double = -1; };
		s.sibsp = v[6];
		s.parch = v[7];
		s.ticket = v[8];
		s.fare = v[9];
		s.cabin = v[10];
		s.embarked = v[11];
		p.push_back(s);
	}
	return i;
}

std::string rep(std::string str1) {
	int begin = 0;
	int off = 0;
	while (begin > -1) {
		begin = str1.find("\"", off);
		if (begin > 0) {
			str1 = str1.replace(begin, 1, "\"\"");
		}
		off = begin + 2;
	}
	return str1;
}

std::ostream& operator<<(std::ostream& o, std::vector<Passenger>& x) {
	for (int i = 0; i < x.size(); i++) {
		o << x[i].survival << ",";
		o << x[i].pclass << ",";
		o << "\"" << rep(x[i].name) << "\",";
		o << x[i].sex << ",";
		o << x[i].age << ",";
		o << x[i].sibsp << ",";
		o << x[i].parch << ",";
		o << x[i].ticket << ",";
		o << x[i].fare << ",";
		o << x[i].cabin << ",";
		o << x[i].embarked << std::endl;
	}
	return o;
}

bool Pred(const Passenger& a, const Passenger& b) {
	return a.age_double < b.age_double;
}

void if_sorted(std::vector<Passenger>& x) {
	std::vector<std::reference_wrapper<Passenger>> pass;
	for (int i = 0; i < x.size(); i++) {
		if ((x[i].sex == "female") && (x[i].survival == "1") && (x[i].pclass == "1")) {
			pass.push_back(std::ref(x[i]));
		}
	}
	for (int i = 0; i < pass.size(); i++) {
		auto it = std::min_element(std::begin(pass) + i, std::end(pass), Pred);
		int id = std::distance(std::begin(pass), it);
		auto temp = pass[id].get();
		pass[id].get() = pass[i].get();
		pass[i].get() = temp;
	}
}

int main()
{
	std::ifstream in("train.csv");
	std::ofstream out("sort.csv");
	std::vector<Passenger> pass;
	in >> pass;
	if_sorted(pass);
	out << pass;
}