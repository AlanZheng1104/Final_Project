#include "Forger.h"
Forger::Forger() {
	name = "test Forger";
	special_tool = "Hammer";
}
Forger::Forger(string in_name, string in_tool) {
	name = in_name;
	special_tool = in_tool;
}

string Forger::show_name() {
	return "[Forger] " + name;

}

float Forger::buy(string tool) {
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



Forger::~Forger() {

}