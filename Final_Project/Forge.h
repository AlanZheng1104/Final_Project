#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Human.h"
#include "Customer.h"
#include "Store.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Forge
{	

	friend class Forge_V2;
	friend class Forge_V3;

protected:
	//attrbute
	string name;
	int num_sword;
	int num_sheild;
	int num_hammer;
	int num_steel;
	int num_copper;
	int num_iron;

public:

	//constructor
	Forge();
	Forge(string in_name, int in_sword = 0, int in_sheild = 0, int in_hammer = 0, int in_steel = 0, int in_copper = 0, int in_iron = 0);

	//method

	virtual void show_inv(Human& human);
	
	virtual void show_inv_2();

	virtual void ordering(Store& store, Human& human);

	virtual void create();

	virtual void sell(Customer& perosn, Human& player);


	//destructor

};

