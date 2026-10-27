#include "Store.h"
Store::Store() {
	metals;
	cost;
}

Store::Store(string in_name) {
	name = in_name;
	metals;
	cost;
}

string Store::show_name() {
	return name;
}

void Store::show_store_inv() {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << metals[i] << " ($" << cost[i] << "/each)" << endl;
	}
	cout << "---------------------------------" << endl << endl;
}