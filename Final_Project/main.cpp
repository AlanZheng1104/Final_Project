#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Human.h"
#include "Customer.h"
#include "Fighter.h"
#include "Forger.h"
#include "Store.h"
#include "Forge.h"
#include "Forge_V2.h"
#include "Forge_V3.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

#define SWORD 45
#define SHEILD 40
#define HAMMER 35
#define ANVIL 60
#define MACE 55
#define ARMOR 110
#define GSWORD 95
#define GHAMMER 105

#define STEEL 15
#define COPPER 10
#define IRON 20
#define TITANIUM 25
#define C_STEEL 20
#define D_SILVER 35
#define GOLD 40


//base
//to make sword you need 1 iron, 1 hour
//to make sheild you need 1 iron 1 copper 1.5 hour
//to make hammer you need 1 steel 1 copper 0.5 hour


//lvl 2
//to make a anvil you need 3 steel
//to make mace you need 1 titanium 1 carbon steel
//to make sword you need 1 iron, 1 hour
//to make sheild you need 1 iron 1 copper 1.5 hour
//to make hammer you need 1 steel 1 copper 0.5 hour

//+15 to the base value of sword, sheild and hammer


//lvl 3
//to make armor you need 1 iron, 1 carbon steel, and 1 dark silver
//to make gsword you need 1 gold, 1 carbon steel
//to make ghammer you need 1 dark silver, 2 titanium
//to make a anvil you need 3 steel
//to make mace you need 1 titanium 1 carbon steel
//to make sword you need 1 iron, 
//to make sheild you need 1 iron 1 copper 
//to make hammer you need 1 steel 1 copper 

//+40 to the base value of sword, sheild, hammer, mace, and anvil



//can make anvil and mace at forge lvl 2
//can buy titanium carbon steel

//can make armor gsword and ghammer at forge lvl 3
//you can buy gold d_silver


int main() {
	srand(time(NULL));
	int quota = 50;
	string name;
	int forge_lvl = 1;
	int day = 1;
	string choice;

	Store Ores("Korvash's Metals");

	int cus_ID = rand() % 7;
	int cus_amt = (rand() % 10) + 5;
	
	Customer* group[15] = {
		new Customer("Mike"),
		new Customer("Zythra"),
		new Forger("Yonder", "Hammer"),
		new Fighter("Jesse", "Sword"),
		new Forger("Achem", "Anvil"),
		new Fighter("Draxos", "Mace"),
		new Forger("Joe", "Hammer"),
		new Fighter("Johnson", "Greatsword"),
		new Fighter("Henry", "Greathammer"),
		new Fighter("Zephyros", "Armor"),
		new Forger("Kharon", "Anvil"),
		new Forger("Nyxara", "Hammer"),
		new Fighter("Varkoth", "Armor"),
		new Fighter("ThaIron", "Mace"),
		new Fighter("Aelthar", "Greathammer")
	};

	cout << "Please choose your username: ";
	cin >> name;

	Human player(name, 500);

	Forge player_forge(name);

	Forge_V2 player_forge_2(player_forge);

	Forge_V3 player_forge_3(player_forge_2);


	cout << "Welcome to The Forge " << player.show_name() << "!" << endl;

	while (player.show_money() > quota) {
		cout << "--------------------------------- Day " << day << " ---------------------------------" << endl;
		cout << "Your current quota for today is $" << quota << endl;

		cout << "-----------------------------------------" << endl;
		cout << "-----------------------------------------" << endl;

		cout << "Welcome to " << Ores.show_name() << endl;
		if (forge_lvl == 1) {
			player_forge.ordering(Ores, player);
			player_forge.create();
			for (int i = 0; i < cus_amt; i++) {
				player_forge.sell(*group[cus_ID], player);
				cus_ID = rand() % 7;
				cout << "-----------------------------------------" << endl;
				cout << "-----------------------------------------" << endl;
			}

		}
		else if (forge_lvl == 2) {
			player_forge_2.ordering(Ores, player);
			player_forge_2.create();
			for (int i = 0; i < cus_amt; i++) {
				player_forge_2.sell(*group[cus_ID], player);
				cus_ID = rand() % 7;
				cout << "-----------------------------------------" << endl;
				cout << "-----------------------------------------" << endl;
			}
		}
		else {
			player_forge_3.ordering(Ores, player);
			player_forge_3.create();
			for (int i = 0; i < cus_amt; i++) {
				player_forge_3.sell(*group[cus_ID], player);
				cus_ID = rand() % 15;
				cout << "-----------------------------------------" << endl;
				cout << "-----------------------------------------" << endl;
			}
		}

		cout << "It is nearing the end of the day...would you like to upgrade your forge? (Upgrading increases base sell value + decrease forge time)" << endl << "You have $" << player.show_money()
			<< endl << "Please type Y or N (Cost to upgrade to level 2 is $100, to level 3 is $300): ";

		cin >> choice;
		if (choice == "Y") {
			if ((forge_lvl == 1) && (player.show_money() >= 100)) {
				forge_lvl = 2;
				cout << "Forge up to level 2!" << endl;
				player.upgrade_cost(100);
			}
			else if ((forge_lvl == 2) && (player.show_money() >= 300)){
				forge_lvl = 3;
				cout << "Forge up to level 3!" << endl;
				player.upgrade_cost(300);
			}
			else {
				cout << "Not enough money!" << endl;

			}
		}
		day++;

		player.quota(quota);

		cout << "You have $" << player.show_money() << " at the end of the day" << endl;
		if (player.show_money() < quota) {
			cout << "You didn't meet quota! Game over!" << endl;
		}
		quota = quota + 50;
	}

	return 0;
}