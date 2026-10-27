#include "Forge_V2.h"
Forge_V2::Forge_V2() : Forge("test",1,2,3,4,5,6) {
	num_mace = 1;
	num_anvil = 3;
	num_titanium = 5;
	num_carbon = 10;
}

Forge_V2::Forge_V2(Forge& inv, int in_mace, int in_anvil, int in_titanium, int in_carbon) {
	//import previous inventory 
	name = inv.name;
	num_sword = inv.num_sword;
	num_sheild = inv.num_sheild;
	num_hammer = inv.num_hammer;
	num_copper = inv.num_copper;
	num_iron = inv.num_iron;
	num_steel = inv.num_steel;

	num_mace = in_mace;
	num_anvil = in_anvil;
	num_titanium = in_titanium;
	num_carbon = in_carbon;
}

void Forge_V2::show_inv(Human& human) {
	cout << "Your current money: " << human.money << endl;

	cout << "Current tool inventory: " << endl << "Swords: " << num_sword << endl << "Sheild: " << num_sheild << endl << "Hammer: " << num_hammer << endl;
	cout << "Mace: " << num_mace << endl << "Anvil: " << num_anvil << endl;

	cout << "Current metal inventory: " << endl << "Iron: " << num_iron << endl << "Copper: " << num_copper << endl << "Steel: " << num_steel << endl;
	cout << "Titanium: " << num_titanium << endl << "Carbon Steel: " << num_carbon << endl;
}


void Forge_V2::show_inv_2() {
	cout << "Current tool inventory: " << endl << "Swords: " << num_sword << endl << "Sheild: " << num_sheild << endl << "Hammer: " << num_hammer << endl
		<< "Anvil: " << num_anvil << endl << "Mace: " << num_mace << endl;


	cout << "Current metal inventory: " << endl << "Iron: " << num_iron << endl << "Copper: " << num_copper << endl << "Steel: " << num_steel << endl
		<< "Titanium: " << num_titanium << endl << "Carbon Steel: " << num_carbon << endl;
}


void Forge_V2::ordering(Store& store, Human& human) {
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
			if (human.money >= (C_STEEL * amt)) {
				cout << "You have bought " << amt << "x Carbon Steel" << endl;
				human.money = human.money - (C_STEEL * amt);
				num_carbon = num_carbon + amt;
			}
			else {
				cout << "Not enough money!" << endl;
			}
			break;
		case 5:
			if (human.money >= (TITANIUM * amt)) {
				cout << "You have bought " << amt << "x Titaniium" << endl;
				human.money = human.money - (TITANIUM * amt);
				num_titanium = num_titanium + amt;
			}
			else {
				cout << "Not enough money!" << endl;
			}
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


void Forge_V2::create() {
	cout << "You have 10 hours to forge" << endl;
	float hour = 0;
	int choice;

	//debug values below
	//num_iron = 10;
	//num_copper = 10;
	//num_steel = 10;

	while (hour < 10) {
		show_inv_2();

		cout << "What would you like to forge (type 0, 1, 2, 3, 4, or 5): ";
		cout << endl << "1. Sword (0.5 hour, 1 Iron)" << endl << "2. Sheild (1 hours, 1 Iron & 1 Copper)" << endl << "3. Hammer (0.5 hour, 1 Steel & 1 Copper)" << endl 
			<< "4. Anvil (3 hours, 3 Steel)" << endl << "5. Mace (2 hours, 1 Titanium & 1 Carbon Steel" << endl << "0. To end forging early" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			hour = 10;
			break;
		case 1:
			if ((num_iron > 0) && (hour + 0.5 <= 10)) {
				num_sword++;
				num_iron = num_iron - 1;
				hour = hour + 0.5;
			}
			else {
				cout << "Not enough material/time!" << endl;
			}
			break;
		case 2:
			if ((num_iron > 0) && (num_copper > 0) && (hour + 1 <= 10)) {
				num_sheild++;
				num_iron = num_iron - 1;
				num_copper = num_copper - 1;
				hour = hour + 1;
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
		case 4:
			if ((num_steel > 2) && (hour + 3 < 8)) {
				num_anvil++;
				num_steel = num_steel - 3;
				hour = hour + 3;
			}
			else {
				cout << "Not enough material/time!" << endl;
			}
			break;
		case 5:
			if ((num_titanium > 0) && (num_carbon > 0) && (hour + 2 <= 10)) {
				num_mace++;
				num_carbon = num_carbon - 1;
				num_titanium = num_titanium - 1;
				hour = hour + 2;
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

void Forge_V2::sell(Customer& person, Human& player) {
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
	cout << "1. Sword, 2. Sheild, 3. Hammer, 4. Anvil, 5. Mace, 0. Nothing" << endl;
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
			player.money = player.money + ((SWORD + 15) * mult);
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
			player.money = player.money + ((SHEILD + 15) * mult);
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
			player.money = player.money + ((HAMMER + 15) * mult);
		}
		else {
			tool = "NA";
			cout << "Out of hammers!" << endl;
			person.buy(tool);
		}
		break;
	case 4:
		if (num_anvil > 0) {
			tool = "Anvil";
			mult = person.buy(tool);
			num_anvil = num_anvil - 1;
			player.money = player.money + (ANVIL * mult);
		}
		else {
			tool = "NA";
			cout << "Out of Anvils!" << endl;
			person.buy(tool);
		}
		break;
	case 5:
		if (num_mace > 0) {
			tool = "Mace";
			mult = person.buy(tool);
			num_mace = num_mace - 1;
			player.money = player.money + (MACE * mult);
		}
		else {
			tool = "NA";
			cout << "Out of Maces!" << endl;
			person.buy(tool);
		}
		break;
	}
}