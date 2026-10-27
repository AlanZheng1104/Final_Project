#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

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


class Store
{	//attributes

	string name;
	string metals[7] = { "Steel", "Copper", "Iron", "Carbon Steel", "Titanium", "Dark Silver", "Gold"};
	int cost[7] = { STEEL, COPPER, IRON, C_STEEL, TITANIUM, D_SILVER, GOLD };

public:

	//constructor
	Store();
	Store(string in_name);


	//method
	void show_store_inv();

	string show_name();





	//destructor
};

