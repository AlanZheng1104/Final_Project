#include "Forge.h"
Forge::Forge() {
	name = "test";
	num_sword = 0;
	num_sheild = 5;
	num_hammer = 8;
	num_copper = 10;
	num_steel = 15;
	num_iron = 20;
}
Forge::Forge(string in_name, int in_sword, int in_sheild, int in_hammer, int in_steel, int in_copper, int in_iron) {
	name = in_name;
	num_sword = in_sword;
	num_sheild = in_sheild;
	num_hammer = in_hammer;
	num_steel = in_steel;
	num_copper = in_copper;
	num_iron = in_iron;
}


void Forge::show_inv(Human& human) {
	cout << "Your current money: $" << human.money << endl;

	cout << "Current tool inventory: " << endl << "Swords: " << num_sword << endl << "Sheild: " << num_sheild << endl << "Hammer: " << num_hammer << endl;

	cout << "Current metal inventory: " << endl << "Iron: " << num_iron << endl << "Copper: " << num_copper << endl << "Steel: " << num_steel << endl;

}

void Forge::show_inv_2() {
	cout << "Current tool inventory: " << endl << "Swords: " << num_sword << endl << "Sheild: " << num_sheild << endl << "Hammer: " << num_hammer << endl;

	cout << "Current metal inventory: " << endl << "Iron: " << num_iron << endl << "Copper: " << num_copper << endl << "Steel: " << num_steel << endl;
}


void Forge::ordering(Store& store, Human& human) {
	int choice = 1;
	int amt;
	while (choice != 0) {

		store.show_store_inv();

		show_inv_2();
		cout << "-----------------------------------------" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "You have $" << human.money << endl;
		cout << "Please type in which metal you want to buy (type 0 to exit): ";
		cin >> choice;

		if (choice != 0) {
			cout << "How many do you want to buy: ";
			cin >> amt;
		}
		switch (choice) {
		case 1:
			if (human.money >= (STEEL * amt)) {
				cout << "You have bought " << amt << "x steel" << endl;
				human.money = human.money - (STEEL * amt);
				num_steel = num_steel + amt;
			}
			else {
				cout << "Not enough money!" << endl;
			}
			break;

		case 2:
			if (human.money >= (COPPER * amt)) {
				cout << "You have bought " << amt << "x copper" << endl;
				human.money = human.money - (COPPER * amt);
				num_copper = num_copper + amt;
			}
			else {
				cout << "Not enough money!" << endl;
			}
			break;

		case 3:
			if (human.money >= (IRON * amt)) {
				cout << "You have bought " << amt << "x Iron" << endl;
				human.money = human.money - (IRON * amt);
				num_iron = num_iron + amt;
			}
			else {
				cout << "Not enough money!" << endl;
			}
			break;

		case 4:
			cout << "Can't buy this yet! (Unlock at forge lvl 2)" << endl;
			break;

		case 5:
			cout << "Can't buy this yet! (Unlock at forge lvl 2)" << endl;
			break;

		case 6:
			cout << "Can't buy this yet! (Unlock at forge lvl 3)" << endl;
			break;

		case 7:
			cout << "Can't buy this yet! (Unlock at forge lvl 3)" << endl;
			break;

		}
		cout << "-----------------------------------------" << endl;
		cout << "-----------------------------------------" << endl;
	}
}


void Forge::create() {
	cout << "You have 10 hours to forge" << endl;
	float hour = 0;
	int choice;

	//debug values below
	//num_iron = 10;
	//num_copper = 10;
	//num_steel = 10;

	while (hour < 10) {
		show_inv_2();

		cout << "You have " << 10 - hour << " left to forge" << endl;

		cout << "What would you like to forge (type 0, 1, 2, or 3): ";
		cout << endl << "1. Sword (1 hour, 1 Iron)" << endl << "2. Sheild (1.5 hours, 1 Iron & 1 Copper)" << endl << "3. Hammer (0.5 hour, 1 Steel & 1 Copper)" << endl << "0. To end forging early" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			hour = 10;
			break;
		case 1:
			if ((num_iron > 0) && (hour + 1 <= 10)) {
				num_sword++;
				num_iron = num_iron - 1;
				hour = hour + 1;
			}
			else {
				cout << "Not enough material/time!" << endl;
			}
			break;
		case 2:
			if ((num_iron > 0) && (num_copper > 0) && (hour + 1.5 <= 10)) {
				num_sheild++;
				num_iron = num_iron - 1;
				num_copper = num_copper - 1;
				hour = hour + 1.5;
			}
			else {
				cout << "Not enough material/time!" << endl;
			}
			break;

		case 3:
			if ((num_steel > 0) && (num_copper > 0) && (hour + 0.5 <= 10)) {
				num_hammer++;
				num_steel = num_steel - 1;
				num_copper = num_copper - 1;
				hour = hour + 0.5;
			}
			else {
				cout << "Not enough material/time!" << endl;
			}
			break;
		}
		cout << "-----------------------------------------" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "You have " << 10 - hour << " left to forge" << endl;

	}
}

void Forge::sell(Customer& person, Human& player) {
	int choice;
	float mult;
	string tool;
	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << person.show_name() << " approaches your bench..." << endl;
	cout << person.show_name() << " I am looking for a " << person.show_tool() << " in mind, you got it?" << endl;


	show_inv_2();
	cout << "You have: $" << player.money << endl;

	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;

	cout << "What would you like to sell to " << person.show_name() << endl;
	cout << "1. Sword, 2. Sheild, 3. Hammer, 0. Nothing" << endl;
	cin >> choice;

	switch (choice) {
	case 0:
		tool = "NA";

		break;
	case 1:
		if (num_sword > 0) {
			tool = "Sword";
			mult = person.buy(tool);
			num_sword = num_sword - 1;
			player.money = player.money + (SWORD * mult);
		}
		else {
			tool = "NA";
			cout << "Out of swords!" << endl;
			person.buy(tool);
		}
		break;
	case 2:
		if (num_sheild > 0) {
			tool = "Sheild";
			mult = person.buy(tool);
			num_sheild = num_sheild - 1;
			player.money = player.money + (SHEILD * mult);
		}
		else {
			tool = "NA";
			cout << "Out of sheilds!" << endl;
			person.buy(tool);
		}
		break;
	case 3:
		if (num_hammer > 0) {
			tool = "Hammer";
			mult = person.buy(tool);
			num_hammer = num_hammer - 1;
			player.money = player.money + (HAMMER * mult);
		}
		else {
			tool = "NA";
			cout << "Out of hammers!" << endl;
			person.buy(tool);
		}
		break;
	}
}