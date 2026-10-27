#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Human
{
	//attribute
	friend class Forge;
	friend class Forge_V2;
	friend class Forge_V3;

protected:
	string name;
	int money;

public:

	//constructor
	Human();
	Human(string in_name, int in_money);

	//method
	string show_name();
	int show_money();
	void quota(int in_quota);
	void upgrade_cost(int in_money);

	//destructor
	~Human();

};

