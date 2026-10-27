#include "Fighter.h"

Fighter::Fighter() {
	name = "test fighter";
	special_tool = "test_tool";
}
Fighter::Fighter(string in_name, string in_tool) {
	name = in_name;
	special_tool = in_tool;
}


string Fighter::show_name() {
	return "[Fighter] " + name;

}

float Fighter::buy(string tool) {
	if (tool == special_tool) {
		cout << "Thank you, I was looking for that!" << endl;
		return 1.15; //multipler
	}
	else if (tool == "NA") {
		cout << "I guess you got nothing to sell" << endl;
		return 0;
	}
	else {
		cout << "Thank you for " << tool << endl;
		return 1;
	}
}


Fighter::~Fighter() {

}