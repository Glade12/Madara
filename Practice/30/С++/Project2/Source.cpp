#include <iostream>
#include <vector>
#include <string>
#include <random>

struct Coin {
	int count;
};

struct Rune {
	int lvl;
	enum  Element { FIRE, WATER, EARTH, AIR } elem;
};



struct Weapon {
	int damage;
	int critical;
	int durability;
};

struct Armor {
	int guard;
	int durability;
};

struct Item {
	enum class ItemType { Coin , Rune, Weapon, Armor} type;
	union val1{ Coin c; Rune r; Weapon w; Armor a; } val;
};

using LootBox = std::vector<Item>;
using Item1 = Item::ItemType;
using Rune1 = Rune::Element;



Item  Bag() {
	std::vector<Item> all;
	int counter;
	Item a;
	for (int i = 0; i < 16; i++) {
		switch (i) {
		case 0: {
			a.val.c.count = 1000;
			counter = 5000;
			break; }
		case 1: {
			a = { Item1::Coin };
			a.val.r.lvl = 1;
			a.val.r.elem = {Rune1::FIRE};
			counter = 600;
			break; }
		case 2: {
			a = { Item1::Rune };
			a.val.r.lvl = 1;
			a.val.r.elem = { Rune1::WATER};
			counter = 1300;
			break; }
		case 3: {
			a = { Item1::Rune };
			a.val.r.lvl = 1;
			a.val.r.elem = { Rune1::EARTH };
			counter = 700;
			break; }
		case 4: {
			a = { Item1::Rune };
			a.val.r.lvl = 1;
			a.val.r.elem = { Rune1::AIR };
			counter = 1400;
			break; }
		case 5: {
			a = { Item1::Rune };
			a.val.r.lvl = 5;
			a.val.r.elem = { Rune1::FIRE };
			counter = 60;
			break; }
		case 6: {
			a = { Item1::Rune };
			a.val.r.lvl = 5;
			a.val.r.elem = { Rune1::WATER };
			counter = 130;
			break; }
		case 7: {
			a = { Item1::Coin };
			a.val.r.lvl = 5;
			a.val.r.elem = { Rune1::EARTH };
			counter = 70; }
		case 8: {
			a = { Item1::Rune };
			a.val.r.lvl = 5;
			a.val.r.elem = { Rune1::AIR };
			counter = 140;
			break; }
		case 9: {
			a = { Item1::Rune };
			a.val.r.lvl = 10;
			a.val.r.elem = { Rune1::FIRE };
			counter = 6;
			break; }
		case 10: {
			a = { Item1::Rune };
			a.val.r.lvl = 10;
			a.val.r.elem = { Rune1::WATER };
			counter = 13;
			break; }
		case 11: {
			a = { Item1::Coin };
			a.val.r.lvl = 10;
			a.val.r.elem = { Rune1::EARTH };
			counter = 7;
			break; }
		case 12: {
			a = { Item1::Rune };
			a.val.r.lvl = 10;
			a.val.r.elem = { Rune1::AIR };
			counter = 14;
			break; }
		case 13: {
			a = { Item1::Weapon };
			a.val.w.damage = 100;
			a.val.w.critical = 0;
			a.val.w.durability = 100;
			counter = 140;
			break; }

		case 14: {
			a = { Item1::Weapon };
			a.val.w.damage = 75;
			a.val.w.critical = 50;
			a.val.w.durability = 100;
			counter = 140;
			break; }

		case 15: {
			a = { Item1::Armor};
			a.val.a.guard= 50;
			a.val.a.durability = 100;
			counter = 280;
			break; }

		}
		while (counter) {
			all.push_back(a);
			counter--;
		}
	}

	int r = 1 + rand() % 10000;
	return (all[r]);

}


Item operator ++ (Item a) {
	Item n = Bag() ;
	return(n) ;
}

LootBox& operator << (LootBox& l, Item i) {
	l.push_back(i);
	return l;
}




std::ostream& operator << (std::ostream& o, Item it) {

	if (it.val.c.count == 1000){
		o << it.val.c.count << " Coins"<<std::endl;
	}
	if ((it.val.r.lvl == 1) or (it.val.r.lvl == 5) or (it.val.r.lvl == 10)) {
		switch (it.val.r.elem) {
			
		case 0:{
			o << "Rune of FIRE " <<   it.val.r.lvl << " level" << std::endl;
			break;
			}
		case 1:{
			o << "Rune of WATER " <<   it.val.r.lvl << " level" << std::endl;
			break;
		}
		case 2:{
			o << "Rune of EARTH " <<   it.val.r.lvl << " level" << std::endl;
			break;
		}
		case 3:{
			o << "Rune of AIR " <<   it.val.r.lvl << " level" << std::endl;
			break;
		}
		}
		
}
	if (it.val.w.damage == 100) {
		o << "Griffit's sword"<<std::endl;;
	}
	if (it.val.w.damage == 75) {
		o << "Gat's sword"<< std::endl;
	}
	if (it.val.a.guard == 50) {
		o << "Unbroken armor"<<std::endl;;
	}
	return o;
}

std::ostream& operator << (std::ostream& os, LootBox lo) {
	for (int i = 0; i < lo.size(); i++) {
		os << lo[i] << std::endl;
	}
	return os;
}

LootBox generateLootBox(){
	LootBox finish;
	for (int i = 0; i < 3; i++) {
		Item a = {};
		finish << ++a;
	}
	return finish;
	
};

int main() {
	setlocale(LC_ALL, "ru");
	while (1) {
		std::cout << "Открыть ЛутБокс ?" << std::endl;
		std::string i;
		std::cin >> i;
		if ((i == "Yes") or (i == "Y") or (i == "y") or (i == "yes")) {
			std::cout << generateLootBox();
		}
		else {
			if ((i == "No") or (i == "N") or (i == "no") or (i == "n")) {
				break;
			}
		}
	}
	

	
	
}


